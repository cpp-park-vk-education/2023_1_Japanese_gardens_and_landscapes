#include "SpriteSystem.hpp"

namespace AnimeDefendersEngine::Graphics::SpriteSystem {

    auto isSpriteVisibleToCamera(const Sprite*, const Camera*) noexcept -> bool {
        return true;
    }

    auto drawSprite(const Sprite* sprite) noexcept -> void {
        auto transpose = sprite->getTranspose();
        auto texture = sprite->getTexture();

        SpriteSystem::transposeMathWrapper.applyTransposeMatrix(transpose);

        if (texture) {
            SpriteSystem::drawTextureWrapper.drawTexture(texture);
        }
    }

}  // namespace AnimeDefendersEngine::Graphics::SpriteSystem
