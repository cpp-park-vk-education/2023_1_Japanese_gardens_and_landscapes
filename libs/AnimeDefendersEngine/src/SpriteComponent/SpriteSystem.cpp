#include "SpriteSystem.hpp"

using namespace AnimeDefendersEngine::Graphics;

auto SpriteSystem::isSpriteVisibleToCamera(const Sprite&, const Camera&) -> bool {
    return false;
}

auto SpriteSystem::drawSprite(const Sprite&) -> void {}
