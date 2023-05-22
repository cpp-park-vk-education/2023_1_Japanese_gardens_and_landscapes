#pragma once

#include "Animation.hpp"
#include "Camera.hpp"
#include "Component.hpp"
#include "Texture.hpp"
#include "Transpose.hpp"

#include <memory>

namespace AnimeDefendersEngine::Graphics {

    class Sprite final : public Component {
     public:
        Sprite(Transpose, Texture*, Animation*);

        auto isSpriteVisibleToCamera(Camera*) const -> bool;
        auto drawSprite() const -> void;

        auto setTranspose(Transpose) -> void;
        auto setTexture(Texture*) -> void;
        auto setAnimation(Animation*) -> void;

        auto getTranspose() const -> Transpose;
        auto getTexture() const -> Texture*;
        auto getAnimation() const -> Animation*;

     private:
        Transpose m_transpose;
        Texture* m_texture;
        Animation* m_animation;
    };

}  // namespace AnimeDefendersEngine::Graphics
