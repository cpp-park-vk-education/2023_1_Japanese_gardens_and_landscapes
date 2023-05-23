#include "Sprite.hpp"
#include "SpriteSystem.hpp"

namespace AnimeDefendersEngine::Graphics {

    Sprite::Sprite(Math::Transpose* transpose, Texture* texture = nullptr, Animation* animation = nullptr) noexcept
        : m_transpose(transpose), m_texture(texture), m_animation(animation) {}

    auto Sprite::isSpriteVisibleToCamera(Camera* camera) const noexcept -> bool {
        return SpriteSystem::isSpriteVisibleToCamera(this, camera);
    }

    auto Sprite::drawSprite() const noexcept -> void {
        return SpriteSystem::drawSprite(this);
    }

    auto Sprite::setTranspose(Math::Transpose* transpose) noexcept -> void {
        m_transpose = transpose;
    }

    auto Sprite::setTexture(Texture* texture) noexcept -> void {
        m_texture = texture;
    }

    auto Sprite::setAnimation(Animation* animation) noexcept -> void {
        m_animation = animation;
    }

    auto Sprite::getTranspose() const noexcept -> Math::Transpose* {
        return m_transpose;
    }

    auto Sprite::getTexture() const noexcept -> Texture* {
        return m_texture;
    }

    auto Sprite::getAnimation() const noexcept -> Animation* {
        return m_animation;
    }

}  // namespace AnimeDefendersEngine::Graphics
