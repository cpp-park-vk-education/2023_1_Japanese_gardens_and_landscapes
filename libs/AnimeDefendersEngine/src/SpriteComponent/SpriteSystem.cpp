#include "SpriteSystem.hpp"

using namespace AnimeDefendersEngine::Graphics;

auto SpriteSystem::isSpriteVisibleToCamera(const Sprite*, const Camera*) -> bool {
    return true;
}

auto SpriteSystem::drawSprite(const Sprite* sprite) -> void {
    Animation* animation = sprite->getAnimation();
    Texture* texture = sprite->getTexture();

    if (animation) {
        return;
    }

    if (texture) {
        drawTextureWrapper.drawTexture(texture);
    }
}
