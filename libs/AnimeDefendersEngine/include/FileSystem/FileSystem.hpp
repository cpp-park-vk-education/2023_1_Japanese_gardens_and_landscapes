#pragma once

#include "Matrix2d.hpp"

#include <filesystem>
#include <string>
#include <unordered_map>

namespace AnimeDefendersEngine {

    struct RGBPixel {
        char r{};
        char g{};
        char b{};
    };

    namespace {
        auto returnPixel(unsigned char* data, std::size_t i, std::size_t j, std::size_t x, std::size_t channelCount) -> RGBPixel {
            RGBPixel pixel;
            unsigned char* pixelOffset = data + (i + x * j) * channelCount;
            pixel.r = pixelOffset[0];
            pixel.g = pixelOffset[1];
            pixel.b = pixelOffset[2];

            return pixel;
        }
    }  // namespace

    namespace FileSystem {

        struct Audio {};

        struct AudioTrack {};

        struct Image {
            Math::Matrix2d<RGBPixel> matrix;
        };

        enum class FileType {
            imagePNG,
            text
        };

        class FileSystem {
         public:
            explicit FileSystem(const std::filesystem::path& pathToRoot);
            auto getImage(const std::string& name) const -> const Image& {return };
            auto loadItem(const std::string& name) -> void {
                if (m_paths.at(name).extension().string() == ".png") {
                    int x{}, y{}, comps{};
                    unsigned char* data = stbi_load(m_paths.at(name).c_str(), &x, &y, &comps, 1);

                    std::vector<RGBPixel> pixels;
                    pixels.reserve(x * y);

                    for (int i = 0; i < x; ++i) {
                        for (int j = 0; j < y; ++j) {
                            pixels.push_back(returnPixel(data, i, j, x, comps));
                        }
                    }

                    m_images[name] = {
                        Math::Matrix2d<RGBPixel>{x, y, pixels}
                    };
                }
            }
            auto deleteItem(FileType type, const std::string& name) -> void;

         private:
            std::unordered_map<std::string, Image> m_images;
            std::unordered_map<std::string, Audio> m_audios;
            std::unordered_map<std::string, AudioTrack> m_audioTracks;
            std::unordered_map<std::string, std::filesystem::path> m_paths;
        };
    }  // namespace FileSystem
}  // namespace AnimeDefendersEngine
