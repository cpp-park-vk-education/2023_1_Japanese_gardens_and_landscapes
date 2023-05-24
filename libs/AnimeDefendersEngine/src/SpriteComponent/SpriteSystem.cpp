#include "DrawTextureWrapper.hpp"
#include "SpriteSystem.hpp"
#include "TransposeMathWrapper.hpp"

namespace AnimeDefendersEngine::Graphics::SpriteSystem {

    namespace {

        const TransposeMathWrapper transposeMathWrapper{};
        const DrawTextureWrapper drawTextureWrapper{};

    }  // namespace

    auto isSpriteVisibleToCamera(const Sprite*, const Camera*) noexcept -> bool {
        return true;
    }

    auto drawSprite(const Sprite* sprite) noexcept -> void {
        auto transpose = sprite->getTranspose();
        auto texture = sprite->getTexture();

        SpriteSystem::transposeMathWrapper.applyTransposeMatrix(transpose);
        SpriteSystem::drawTextureWrapper.drawTexture(texture);
    }

}  // namespace AnimeDefendersEngine::Graphics::SpriteSystem
