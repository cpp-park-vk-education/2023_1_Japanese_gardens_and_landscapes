#pragma once

#include "IDrawTextureWrapper.hpp"

namespace AnimeDefendersEngine {
    namespace Graphics {

        class DrawTextureWrapper : public IDrawTextureWrapper {
         public:
            auto drawTexture(const Image&) -> void const override;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
