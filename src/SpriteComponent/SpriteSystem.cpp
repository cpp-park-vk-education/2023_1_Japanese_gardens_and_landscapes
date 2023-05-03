#pragma once

#include "SpriteSystem.hpp"

auto SpriteSystem::findVisibleSprites(const std::vector<Sprite *> &, Camera *)
    -> std::vector<Sprite *> {}

auto SpriteSystem::drawSprite(Sprite *) -> void {}
