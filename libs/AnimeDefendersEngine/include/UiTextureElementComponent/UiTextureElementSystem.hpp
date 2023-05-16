#pragma once

#include "UiElementSystem.hpp"
#include "UiTextureElement.hpp"

namespace AnimeDefendersEngine {
    namespace Graphics {

        class UiTextureElementSystem : public UiElementSystem {
         public:
            static auto applyUiElementTransform(const UiTextureElement&) -> void;
            static auto drawUiElement(const UiTextureElement&) -> void;
            static auto checkByPointInclude(const UiTextureElement&, int, int) -> bool;

         private:
            UiTextureElementSystem();
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
