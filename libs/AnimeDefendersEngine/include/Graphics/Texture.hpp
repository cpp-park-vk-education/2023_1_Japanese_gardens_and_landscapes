#pragma once

#include <array>

namespace AnimeDefendersEngine::Graphics {

    struct Texture {
        unsigned int textureId{};
        static constexpr std::array<float, 8> vertexCoords{-1, -1, 1, -1, 1, 1, -1, 1};
        static constexpr std::array<float, 8> textureCoords{0, 0, 1, 0, 1, 1, 0, 1};
    };

}  // namespace AnimeDefendersEngine::Graphics
