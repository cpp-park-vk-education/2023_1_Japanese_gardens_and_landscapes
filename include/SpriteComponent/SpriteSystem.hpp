#pragma once

#include "Camera.hpp"
#include "ISystem.hpp"
#include "Sprite.hpp"

#include <vector>

namespace AnimeDefendersEngine {
    namespace Graphics {

        class SpriteSystem : public ISystem {
         public:
            static auto isSpriteVisibleToCamera(const Sprite&, const Camera&) -> bool const;
            static auto drawSprite(const Sprite&) -> void const;

         private:
            SpriteSystem();
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
