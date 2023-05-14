#pragma once

#include "Animation.hpp"
#include "Camera.hpp"
#include "Component.hpp"
#include "Texture.hpp"
#include "Transform.hpp"

namespace AnimeDefendersEngine {
    namespace Graphics {

        class Sprite : public Component {
         public:
            auto isSpriteVisibleToCamera(Camera*) -> bool const;
            auto drawSprite() -> void const;

            auto setTransform(const Transform&) -> void;
            auto setTexture(Texture) -> void;
            auto setAnimation(Animation) -> void;

         private:
            const Transform& m_transform;
            Texture m_texture;
            Animation m_animation;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
