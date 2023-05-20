#pragma once

#include "FileSystem.hpp"

#include <array>

namespace AnimeDefendersEngine {
    namespace Graphics {

        struct Texture {
            unsigned int textureId{};
            static constexpr std::array<float, 12> vertexCoords{-1, -1, 0, 1, -1, 0, 1, 1, 0, -1, 1, 0};
            static constexpr std::array<float, 8> texureCoords{0, 0, 1, 0, 1, 1, 0, 1};
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
