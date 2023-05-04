#pragma once

#include "Camera.hpp"
#include "ISystem.hpp"
#include "Sprite.hpp"

#include <vector>

namespace AnimeDefendersEngine {

    class SpriteSystem : public ISystem {
     public:
        static auto findVisibleSprites(const std::vector<Sprite*>&, Camera*) -> std::vector<Sprite*> const;
        static auto drawSprite(Sprite*) -> void const;

     private:
        SpriteSystem();
    };

}  // namespace AnimeDefendersEngine
