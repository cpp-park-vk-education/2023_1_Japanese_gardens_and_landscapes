#pragma once

#include <array>

namespace AnimeDefendersEngine::Graphics {

    struct Texture {
        unsigned int textureId{};
        /// @brief Container of x/y coords for set fullscreen draw option
        static constexpr std::array<float, 8> vertexCoords{-1, -1, 1, -1, 1, 1, -1, 1};
        /// @brief Container of x/y coords for setting part of texture to draw
        static constexpr std::array<float, 8> textureCoords{0, 1, 0, 0, 1, 0, 1, 1};
    };

}  // namespace AnimeDefendersEngine::Graphics
