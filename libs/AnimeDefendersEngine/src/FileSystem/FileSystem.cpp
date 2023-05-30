#include "FileSystem.hpp"
#include "Logger.hpp"

#include "stb_image.h"

#include <iostream>
#include <limits>
#include <span>

namespace AnimeDefendersEngine::FileSystem {

    namespace {

        const std::string fileTitleColumnName{"Name"};
        const std::string filePathColumnName{"FilePath"};

        constexpr auto maxRedColorValue = std::numeric_limits<decltype(Graphics::Color::red)>::max();
        constexpr auto minBlueColorValue = std::numeric_limits<decltype(Graphics::Color::blue)>::min();
        constexpr auto minGreenColorValue = std::numeric_limits<decltype(Graphics::Color::green)>::min();
        constexpr auto minAlphaValue = std::numeric_limits<decltype(Graphics::Color::alpha)>::min();

        constexpr Graphics::Color red = {maxRedColorValue, minBlueColorValue, minGreenColorValue, minAlphaValue};

        struct StbiImageDeleter {
            auto operator()(stbi_uc* data) const -> void { stbi_image_free(data); }
        };

        constexpr std::size_t numOfBytesPerPixel = 4;

    }  // namespace

    namespace {

        /**
         * @param data Matrix of pixels stored in array
         *
         */
        auto getPixelByIndex(std::span<const stbi_uc> data, std::size_t rowIndex, std::size_t columnIndex, std::size_t numberOfRows,
                             std::size_t channelCount) -> const std::span<const stbi_uc> {
            return data.subspan((rowIndex + numberOfRows * columnIndex) * channelCount, numOfBytesPerPixel);
        }

        [[nodiscard]] auto readPixel(std::span<const stbi_uc> data, std::size_t rowIndex, std::size_t columnIndex, std::size_t numberOfRows,
                                     std::size_t channelCount) -> Graphics::Color {
            Graphics::Color pixel{};

            const auto pixelOffset = getPixelByIndex(data, rowIndex, numberOfRows, columnIndex, channelCount);

            pixel.red = pixelOffset[0];
            pixel.green = pixelOffset[1];
            pixel.blue = pixelOffset[2];
            pixel.alpha = pixelOffset[3];

            return pixel;
        }

        [[nodiscard]] auto createErrorImage(std::size_t width = 10, std::size_t height = 10) -> Image {
            std::vector<Graphics::Color> pixels(width * height, red);

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

        int numOfRows{};
        int numOfColumns{};
        int numOfChannels{};

        std::unique_ptr<stbi_uc, StbiImageDeleter> data{stbi_load(m_paths.at(name).c_str(), &numOfRows, &numOfColumns, &numOfChannels, 0)};

        if (!data) {
            Logger::defaultLog.printError("Failed to load image from " + m_paths.at(name).string() + " error while reading file");
            m_images[name] = createErrorImage();
            return;
        }

        const auto numOfPixels = numOfRows * numOfColumns;

        std::vector<Graphics::Color> pixels{};
        pixels.reserve(numOfPixels);

        for (int i = 0; i < numOfRows; ++i) {
            for (int j = 0; j < numOfColumns; ++j) {
                std::span<stbi_uc> dataWrapper{data.get(), numOfPixels * numOfChannels};
                pixels.push_back(readPixel(dataWrapper, i, j, numOfRows, numOfChannels));
            }
        }

        m_images[name] = Image{static_cast<std::size_t>(numOfRows), static_cast<std::size_t>(numOfColumns), std::move(pixels)};
        Logger::defaultLog.printMessage("Image '" + name + "' loaded from " + m_paths.at(name).string() + " successfully");
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
