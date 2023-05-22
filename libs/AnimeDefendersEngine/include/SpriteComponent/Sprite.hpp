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
        Sprite(Transpose*, Texture*, Animation*) noexcept;

        [[nodiscard]] auto isSpriteVisibleToCamera(Camera*) const -> bool;
        auto drawSprite() const noexcept -> void;

        auto setTranspose(Transpose*) noexcept -> void;
        auto setTexture(Texture*) noexcept -> void;
        auto setAnimation(Animation*) noexcept -> void;

        [[nodiscard]] auto getTranspose() const noexcept -> Transpose*;
        [[nodiscard]] auto getTexture() const noexcept -> Texture*;
        [[nodiscard]] auto getAnimation() const noexcept -> Animation*;

     private:
        Transpose* m_transpose;
        Texture* m_texture;
        Animation* m_animation;
    };

}  // namespace AnimeDefendersEngine::Graphics
