#pragma once

#include "Color.hpp"
#include "Matrix2d.hpp"
#include "Texture.hpp"

namespace AnimeDefendersEngine::Graphics {

    class IDrawTextureWrapper {
     public:
        virtual ~IDrawTextureWrapper() = default;

        [[nodiscard]] virtual auto loadTexture(const Math::Matrix2d<Color>& pixelMatrix) const noexcept -> Texture = 0;
        virtual auto drawTexture(const Texture&) const noexcept -> void = 0;
    };

}  // namespace AnimeDefendersEngine::Graphics
