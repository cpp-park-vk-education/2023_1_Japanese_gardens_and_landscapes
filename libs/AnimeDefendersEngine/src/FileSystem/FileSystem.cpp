#include "FileSystem.hpp"

#include <iostream>
#include "stb_image.h"

namespace AnimeDefendersEngine::FileSystem {

    namespace {

        auto returnPixel(unsigned char* data, std::size_t i, std::size_t j, std::size_t x, std::size_t channelCount) -> Color {
            Color pixel;
            const unsigned char* pixelOffset = data + (i + x * j) * channelCount;
            pixel.red = pixelOffset[0];
            pixel.green = pixelOffset[1];
            pixel.blue = pixelOffset[2];
            pixel.alpha = pixelOffset[3];

            return pixel;
        }

    }  // namespace

    FileSystem::FileSystem(const std::filesystem::path& pathToRoot) {
        TableReader reader{std::make_unique<std::ifstream>(pathToRoot), '|'};
        while (!reader.endOfTable()) {
            m_paths[reader["Name"]] = absolutePath(reader["FilePath"]);
            
            reader.readNewRow();
        }

        for (const auto& [name, path] : m_paths) {
            std::cout << "name = '" << name << "' path = '" << path.c_str() << "'\n";
        }
    }

    auto FileSystem::loadItem(const std::string& name) -> void {
        if (m_paths.at(name).extension().string() == ".png") {
            int x{}, y{}, comps{};
            unsigned char* data = stbi_load(m_paths.at(name).c_str(), &x, &y, &comps, 0);

            std::vector<Color> pixels;
            pixels.reserve(x * y);

            for (int i = 0; i < x; ++i) {
                for (int j = 0; j < y; ++j) {
                    pixels.push_back(returnPixel(data, i, j, x, comps));
                }
            }

            m_images[name] = Image{static_cast<std::size_t>(x), static_cast<std::size_t>(y), pixels};
        }
    }

    auto FileSystem::getImage(const std::string& name) -> const Image& {
        if (!m_images.contains(name)) {
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
