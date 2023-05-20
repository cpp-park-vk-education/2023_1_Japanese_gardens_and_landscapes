#pragma once

#include "Animation.hpp"
#include "Camera.hpp"
#include "Component.hpp"
#include "DrawTextureWrapper.hpp"
#include "Texture.hpp"
#include "Transform.hpp"

#include <memory>

namespace AnimeDefendersEngine {
    namespace Graphics {

        class Sprite : public Component {
         public:
            Sprite(Transform*);

            auto isSpriteVisibleToCamera(Camera*) const -> bool;
            auto drawSprite() const -> void;

            auto setTransform(Transform*) -> void;
            auto setTexture(Texture*) -> void;
            auto setAnimation(Animation*) -> void;

            auto getTransform() const -> Transform*;
            auto getTexture() const -> Texture*;
            auto getAnimation() const -> Animation*;

         private:
            Transform* m_transform;
            Texture* m_texture;
            Animation* m_animation;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
