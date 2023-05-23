#pragma once

#include "DrawTextureWrapper.hpp"
#include "Sprite.hpp"
#include "TransposeMathWrapper.hpp"

#include <vector>

namespace AnimeDefendersEngine::Graphics::SpriteSystem {

    auto isSpriteVisibleToCamera(const Sprite*, const Camera*) -> bool;
    auto drawSprite(const Sprite*) noexcept -> void;

    constexpr TransposeMathWrapper transposeMathWrapper{};
    constexpr DrawTextureWrapper drawTextureWrapper{};

}  // namespace AnimeDefendersEngine::Graphics::SpriteSystem
