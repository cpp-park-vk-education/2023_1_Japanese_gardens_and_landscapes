#pragma once

#include "Camera.hpp"
#include "Component.hpp"
#include "Texture.hpp"
#include "Transpose.hpp"

namespace AnimeDefendersEngine::Graphics {

    class Sprite final : public Component {
     public:
        explicit Sprite(const std::string&, const Math::Transpose&, const Texture&) noexcept;

        [[nodiscard]] auto isSpriteVisibleToCamera(const Camera*) const noexcept -> bool;
        auto drawSprite() const noexcept -> void;

        auto setTranspose(const Math::Transpose&) noexcept -> void;
        auto setTexture(const Texture&) noexcept -> void;

        [[nodiscard]] auto getTranspose() const noexcept -> const Math::Transpose&;
        [[nodiscard]] auto getTexture() const noexcept -> const Texture&;

     private:
        Math::Transpose m_transpose;
        Texture m_texture;
    };

}  // namespace AnimeDefendersEngine::Graphics
