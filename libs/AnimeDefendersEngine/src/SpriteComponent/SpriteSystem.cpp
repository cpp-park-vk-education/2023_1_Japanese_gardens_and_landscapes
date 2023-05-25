#include "SpriteSystem.hpp"

namespace AnimeDefendersEngine::Graphics::SpriteSystem {

    auto isSpriteVisibleToCamera(const Sprite*, const Camera*) noexcept -> bool {
        return true;
    }

    auto drawSprite(const Sprite* sprite) noexcept -> void {
        auto transposeMathWrapper = sprite->getTransposeMathWrapper();
        auto drawTextureWrapper = sprite->getDrawTextureWrapper();

        auto transpose = sprite->getTranspose();
        auto texture = sprite->getTexture();

        transposeMathWrapper.applyTransposeMatrix(transpose);
        drawTextureWrapper.drawTexture(texture);
    }

}  // namespace AnimeDefendersEngine::Graphics::SpriteSystem
