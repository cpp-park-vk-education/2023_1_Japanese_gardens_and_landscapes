#pragma once

#include "Sprite.hpp"

namespace AnimeDefendersEngine::Graphics::SpriteSystem {

    auto isSpriteVisibleToCamera(const Sprite*, const Camera*) noexcept -> bool;
    auto drawSprite(const Sprite*) noexcept -> void;

}  // namespace AnimeDefendersEngine::Graphics::SpriteSystem
