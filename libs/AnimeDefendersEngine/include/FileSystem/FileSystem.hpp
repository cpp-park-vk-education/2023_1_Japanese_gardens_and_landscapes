#pragma once

#include "Color.hpp"
#include "Matrix2d.hpp"
#include "TableReader.hpp"

#include <concepts>
#include <filesystem>
#include <fstream>
#include <string>
#include <unordered_map>

#ifndef SOURCE_DIR_PATH
#define SOURCE_DIR_PATH ""
#endif

inline auto absolutePath(const std::filesystem::path& relativePath) -> std::filesystem::path {
    return std::string{SOURCE_DIR_PATH} + relativePath.string();
}

namespace AnimeDefendersEngine {

    namespace FileSystem {

        struct Audio {};

        struct AudioTrack {};

        using Image = Math::Matrix2d<Graphics::Color>;

        enum class FileType {
            imagePNG,
            text
        };

        class FileSystem {
         public:
            explicit FileSystem(const std::filesystem::path& pathToRoot);

            auto loadItem(const std::string& name) -> void;
            [[nodiscard]] auto getImage(const std::string& name) -> const Image&;

            auto deleteItem(FileType type, const std::string& name) -> void;

         private:
            std::unordered_map<std::string, Image> m_images;
            std::unordered_map<std::string, Audio> m_audios;
            std::unordered_map<std::string, AudioTrack> m_audioTracks;

            std::unordered_map<std::string, std::filesystem::path> m_paths;
        };

    }  // namespace FileSystem

}  // namespace AnimeDefendersEngine
