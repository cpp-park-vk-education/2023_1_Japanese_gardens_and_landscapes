#include "Sprite.hpp"

using namespace AnimeDefendersEngine;

auto Sprite::isSpriteVisibleToCamera(Camera*) -> bool const {}

auto Sprite::drawSprite() -> void const {}

auto Sprite::setTransform(const Transform&) -> void {}

auto Sprite::setTexture(Texture) -> void {}

auto Sprite::setAnimation(Animation) -> void {}
