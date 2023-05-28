#include "FileSystem.hpp"
#include "Logger.hpp"

#include "stb_image.h"

#include <iostream>
#include <limits>

namespace AnimeDefendersEngine::FileSystem {

    namespace {

        const std::string fileTitleColumnName{"Name"};
        const std::string filePathColumnName{"FilePath"};

        constexpr auto maxRedColorValue = std::numeric_limits<decltype(Graphics::Color::red)>::max();
        constexpr auto minBlueColorValue = std::numeric_limits<decltype(Graphics::Color::blue)>::min();
        constexpr auto minGreenColorValue = std::numeric_limits<decltype(Graphics::Color::green)>::min();
        constexpr auto minAlphaValue = std::numeric_limits<decltype(Graphics::Color::alpha)>::min();

        constexpr Graphics::Color redPixel = {maxRedColorValue, minBlueColorValue, minGreenColorValue, minAlphaValue};

        struct StbiImageDeleter {
            auto operator()(stbi_uc* data) const -> void { stbi_image_free(data); }
        };

    }  // namespace

    namespace {

        [[nodiscard]] auto readPixel(const unsigned char* data, std::size_t rowIndex, std::size_t columnIndex, std::size_t numberOfRows,
                                     std::size_t channelCount) -> Graphics::Color {
            Graphics::Color pixel{};

            const unsigned char* pixelOffset = data + (rowIndex + numberOfRows * columnIndex) * channelCount;

            pixel.red = pixelOffset[0];
            pixel.green = pixelOffset[1];
            pixel.blue = pixelOffset[2];
            pixel.alpha = pixelOffset[3];

            return pixel;
        }

        [[nodiscard]] auto createErrorImage(std::size_t width = 10, std::size_t height = 10) -> Image {
            std::vector<Graphics::Color> pixels(width * height);

            for (auto& pixel : pixels) {
                pixel = redPixel;
            }

            return Image{width, height, std::move(pixels)};
        }

    }  // namespace

    FileSystem::FileSystem(const std::filesystem::path& pathToRoot) {
        TableReader reader{std::make_unique<std::ifstream>(pathToRoot), '|'};
        while (!reader.endOfTable()) {
            m_paths[reader[fileTitleColumnName]] = absolutePath(reader[filePathColumnName]);

            reader.readNewRow();
        }
    }

    auto FileSystem::loadItem(const std::string& name) -> void {
        if (m_paths.at(name).extension().string() != ".png") {
            return;
        }

        int x{};
        int y{};
        int comps{};

        std::unique_ptr<stbi_uc, StbiImageDeleter> data{stbi_load(m_paths.at(name).c_str(), &x, &y, &comps, 0)};

        if (!data) {
            Logger::defaultLog.printError("Failed to load image from " + m_paths.at(name).string() + " error while reading file");
            m_images[name] = createErrorImage();
            return;
        }

        std::vector<Graphics::Color> pixels{};
        pixels.reserve(x * y);

        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                pixels.push_back(readPixel(data.get(), i, j, x, comps));
            }
        }

        m_images[name] = Image{static_cast<std::size_t>(x), static_cast<std::size_t>(y), std::move(pixels)};
    }

    auto FileSystem::getImage(const std::string& name) -> const Image& {
        if (!m_paths.contains(name) || !std::filesystem::exists(m_paths[name])) {
            Logger::defaultLog.printError("Failed to load image '" + name + "' file not found");
            m_images[name] = createErrorImage();
        } else if (!m_images.contains(name)) {
            loadItem(name);
        }

        return m_images[name];
    }

    auto FileSystem::deleteItem(FileType type, const std::string& name) -> void {
        switch (type) {
            case FileType::imagePNG:
                m_images.erase(name);
                break;

            default:
                break;
        }
    };

}  // namespace AnimeDefendersEngine::FileSystem
