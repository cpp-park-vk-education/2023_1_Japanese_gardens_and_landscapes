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
        explicit Sprite(const std::string&, Math::Transpose*, Texture*, Animation*) noexcept;

        [[nodiscard]] auto isSpriteVisibleToCamera(const Camera*) const -> bool;
        auto drawSprite() const noexcept -> void;

        auto setTranspose(Math::Transpose*) noexcept -> void;
        auto setTexture(Texture*) noexcept -> void;
        auto setAnimation(Animation*) noexcept -> void;

        [[nodiscard]] auto getTranspose() const noexcept -> Math::Transpose*;
        [[nodiscard]] auto getTexture() const noexcept -> Texture*;
        [[nodiscard]] auto getAnimation() const noexcept -> Animation*;

     private:
        Math::Transpose* m_transpose;
        Texture* m_texture;
        Animation* m_animation;
    };

}  // namespace AnimeDefendersEngine::Graphics
