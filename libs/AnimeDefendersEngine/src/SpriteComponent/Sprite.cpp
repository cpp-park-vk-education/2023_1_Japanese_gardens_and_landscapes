#include "Sprite.hpp"
#include "SpriteSystem.hpp"

using namespace AnimeDefendersEngine::Graphics;

Sprite::Sprite(Transpose transpose = Transpose{}, Texture* texture = nullptr, Animation* animation = nullptr)
    : m_transpose(transpose), m_texture(texture), m_animation(animation) {}

auto Sprite::isSpriteVisibleToCamera(Camera* camera) const -> bool {
    return SpriteSystem::isSpriteVisibleToCamera(this, camera);
}

auto Sprite::drawSprite() const -> void {
    return SpriteSystem::drawSprite(this);
}

auto Sprite::setTranspose(Transpose transpose) -> void {
    m_transpose = transpose;
}

auto Sprite::setTexture(Texture* texture) -> void {
    m_texture = texture;
}

auto Sprite::setAnimation(Animation* animation) -> void {
    m_animation = animation;
}

auto Sprite::getTranspose() const -> Transpose {
    return m_transpose;
}

auto Sprite::getTexture() const -> Texture* {
    return m_texture;
}

auto Sprite::getAnimation() const -> Animation* {
    return m_animation;
}
