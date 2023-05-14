#pragma once

#include "IDrawTextureWrapper.hpp"

namespace AnimeDefendersEngine {
    namespace Graphics {

        class DrawTextureWrapper : public IDrawTextureWrapper {
         public:
            auto drawTexture(Image&) -> void const override;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
