#pragma once

#include "IDrawTextureWrapper.hpp"

namespace AnimeDefendersEngine::Graphics {

    class DrawTextureWrapper final : public IDrawTextureWrapper {
     public:
        auto loadTexture(const Math::Matrix2d<Color>&) const -> Texture override;
        auto drawTexture(const Texture&) const -> void override;
    };

}  // namespace AnimeDefendersEngine::Graphics
