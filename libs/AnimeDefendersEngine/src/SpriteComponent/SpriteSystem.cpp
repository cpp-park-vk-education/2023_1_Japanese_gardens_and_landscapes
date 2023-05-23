#include "SpriteSystem.hpp"

namespace AnimeDefendersEngine::Graphics::SpriteSystem {

    auto isSpriteVisibleToCamera(const Sprite*, const Camera*) noexcept -> bool {
        return true;
    }

    auto drawSprite(const Sprite* sprite) noexcept -> void {
        Math::Transpose* transpose = sprite->getTranspose();
        Animation* animation = sprite->getAnimation();
        Texture* texture = sprite->getTexture();

        SpriteSystem::transposeMathWrapper.applyTransposeMatrix(transpose);

        if (animation) {
            return;
        }

        if (texture) {
            SpriteSystem::drawTextureWrapper.drawTexture(texture);
        }
    }

}  // namespace AnimeDefendersEngine::Graphics::SpriteSystem
