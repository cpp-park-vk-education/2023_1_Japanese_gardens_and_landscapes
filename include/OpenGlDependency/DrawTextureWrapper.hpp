#pragma once

#include "IDrawTextureWrapper.hpp"

namespace AnimeDefendersEngine {

    class DrawTextureWrapper : public IDrawTextureWrapper {
     public:
        auto drawTexture(Image&) -> void const override;
    };

}  // namespace AnimeDefendersEngine
