#pragma once

#include "Color.hpp"
#include "Matrix2d.hpp"
#include "Texture.hpp"

namespace AnimeDefendersEngine {
    namespace Graphics {

        class IDrawTextureWrapper {
         public:
            virtual auto loadTexture(const Math::Matrix2d<Color>&) const -> Texture = 0;
            virtual auto drawTexture(const Texture&) const -> void = 0;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
