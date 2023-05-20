#include "SpriteSystem.hpp"

using namespace AnimeDefendersEngine::Graphics;

auto SpriteSystem::isSpriteVisibleToCamera(const Sprite*, const Camera*) -> bool {
    return true;
}

auto SpriteSystem::drawSprite(const Sprite* sprite) -> void {
    Transpose transpose = sprite->getTranspose();
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
