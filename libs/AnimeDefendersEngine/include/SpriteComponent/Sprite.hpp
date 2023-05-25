#pragma once

#include "BaseComponent.hpp"
#include "Camera.hpp"
#include "DrawTextureWrapper.hpp"
#include "Texture.hpp"
#include "Transpose.hpp"
#include "TransposeMathWrapper.hpp"

namespace AnimeDefendersEngine::Graphics {

    class Sprite final : public BaseComponent<Sprite> {
     public:
        Sprite(const std::string& entityId, ComponentManager&, const Math::Transpose&, const Texture&) noexcept;

        [[nodiscard]] auto isSpriteVisibleToCamera(const Camera*) const noexcept -> bool;
        auto drawSprite() const noexcept -> void;

        auto setTranspose(const Math::Transpose&) noexcept -> void;
        auto setTexture(const Texture&) noexcept -> void;

        [[nodiscard]] auto getTranspose() const noexcept -> const Math::Transpose&;
        [[nodiscard]] auto getTexture() const noexcept -> const Texture&;
        [[nodiscard]] auto getTransposeMathWrapper() const noexcept -> const ITransposeMathWrapper&;
        [[nodiscard]] auto getDrawTextureWrapper() const noexcept -> const IDrawTextureWrapper&;

     private:
        Math::Transpose m_transpose;
        Texture m_texture;

        const TransposeMathWrapper& m_transposeMathWrapper{};
        const DrawTextureWrapper& m_drawTextureWrapper{};
    };

}  // namespace AnimeDefendersEngine::Graphics
