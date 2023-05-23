#pragma once

#include "Animation.hpp"
#include "Camera.hpp"
#include "Component.hpp"
#include "Texture.hpp"
#include "Transpose.hpp"

namespace AnimeDefendersEngine {
    namespace Graphics {

        class Sprite : public Component {
         public:
            auto isSpriteVisibleToCamera(const Camera&) -> bool;
            auto drawSprite() -> void;

            auto setTranspose(const Math::Transpose*) -> void;
            auto setTexture(Texture) -> void;
            auto setAnimation(Animation) -> void;

         private:
            const Math::Transpose* m_Transpose;
            Texture m_texture;
            Animation m_animation;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
