#include "Sprite.hpp"

using namespace AnimeDefendersEngine::Graphics;

auto Sprite::isSpriteVisibleToCamera(const Camera*) -> bool {
    return false;
}

auto Sprite::drawSprite() -> void {}

auto Sprite::setTransform(const Transform*) -> void {}

auto Sprite::setTexture(Texture) -> void {}

auto Sprite::setAnimation(Animation) -> void {}
