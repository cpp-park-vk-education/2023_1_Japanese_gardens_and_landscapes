#pragma once

#include "Sprite.hpp"

auto Sprite::isSpriteVisibleToCamera(Camera*) -> bool {}

auto Sprite::drawSprite() -> void {}

auto Sprite::setTransform(const Transform&) -> void {}

auto Sprite::setTexture(Texture) -> void {}

auto Sprite::setAnimation(Animation) -> void {}
