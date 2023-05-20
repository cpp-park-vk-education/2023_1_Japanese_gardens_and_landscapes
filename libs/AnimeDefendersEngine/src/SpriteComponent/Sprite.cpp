#include "Sprite.hpp"
#include "SpriteSystem.hpp"

using namespace AnimeDefendersEngine::Graphics;

Sprite::Sprite(Transform* transform) : m_transform(transform) {}

auto Sprite::isSpriteVisibleToCamera(Camera* camera) const -> bool {
    return SpriteSystem::isSpriteVisibleToCamera(this, camera);
}

auto Sprite::drawSprite() const -> void {
    return SpriteSystem::drawSprite(this);
}

auto Sprite::setTransform(Transform* transform) -> void {
    m_transform = transform;
}

auto Sprite::setTexture(Texture* texture) -> void {
    m_texture = texture;
}

auto Sprite::setAnimation(Animation* animation) -> void {
    m_animation = animation;
}

auto Sprite::getTransform() const -> Transform* {
    return m_transform;
}

auto Sprite::getTexture() const -> Texture* {
    return m_texture;
}

auto Sprite::getAnimation() const -> Animation* {
    return m_animation;
}
