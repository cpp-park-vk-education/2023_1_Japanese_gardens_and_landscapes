#include "Sprite.hpp"
#include "SpriteSystem.hpp"

namespace AnimeDefendersEngine::Graphics {

    Sprite::Sprite(const std::string& entityId, ComponentManager& componentManager, const Math::Transpose& transpose,
                   const Texture& texture) noexcept
        : BaseComponent(entityId, componentManager), m_transpose(transpose), m_texture(texture) {}

    auto Sprite::isSpriteVisibleToCamera(const Camera* camera) const noexcept -> bool {
        return SpriteSystem::isSpriteVisibleToCamera(this, camera);
    }

    auto Sprite::drawSprite() const noexcept -> void {
        return SpriteSystem::drawSprite(this);
    }

    auto Sprite::setTranspose(const Math::Transpose& transpose) noexcept -> void {
        m_transpose = transpose;
    }

    auto Sprite::setTexture(const Texture& texture) noexcept -> void {
        m_texture = texture;
    }

    auto Sprite::getTranspose() const noexcept -> const Math::Transpose& {
        return m_transpose;
    }

    auto Sprite::getTexture() const noexcept -> const Texture& {
        return m_texture;
    }

    auto Sprite::getTransposeMathWrapper() noexcept -> ITransposeMathWrapper& {
        return m_transposeMathWrapper;
    }

    auto Sprite::getDrawTextureWrapper() noexcept -> IDrawTextureWrapper& {
        return m_drawTextureWrapper;
    }

}  // namespace AnimeDefendersEngine::Graphics
