#pragma once

#include "IDrawTextureWrapper.hpp"

namespace AnimeDefendersEngine::Graphics {

    class DrawTextureWrapper final : public IDrawTextureWrapper {
     public:
        [[nodiscard]] auto loadTexture(const Math::Matrix2d<Color>&) const noexcept -> Texture override;
        auto drawTexture(const Texture&) const noexcept -> void override;
    };

}  // namespace AnimeDefendersEngine::Graphics
