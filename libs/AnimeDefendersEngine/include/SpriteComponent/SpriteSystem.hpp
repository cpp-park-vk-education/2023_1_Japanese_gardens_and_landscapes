#pragma once

#include "Camera.hpp"
#include "DrawTextureWrapper.hpp"
#include "ISystem.hpp"
#include "Sprite.hpp"
#include "TransposeMathWrapper.hpp"

#include <vector>

namespace AnimeDefendersEngine {
    namespace Graphics {

        class SpriteSystem : public ISystem {
         public:
            static auto isSpriteVisibleToCamera(const Sprite*, const Camera*) -> bool;
            static auto drawSprite(const Sprite*) -> void;

         private:
            SpriteSystem();

            static constexpr TransposeMathWrapper transposeMathWrapper{};
            static constexpr DrawTextureWrapper drawTextureWrapper{};
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
