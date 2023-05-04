#pragma once

#include <vector>

#include "Camera.hpp"
#include "ISystem.hpp"
#include "Scene.hpp"
#include "Sprite.hpp"

class SpriteSystem : public System {
 public:
    SpriteSystem() = 0;

    static auto findVisibleSprites(const std::vector<Sprite*>&, Camera*) -> std::vector<Sprite*>;
    static auto drawSprite(Sprite*) -> void;
};
