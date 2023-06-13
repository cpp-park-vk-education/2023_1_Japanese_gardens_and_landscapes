#pragma once

#include "ISystem.hpp"
#include "UiElement.hpp"

namespace AnimeDefendersEngine {
    namespace Graphics {

        class UiElementSystem : public ISystem {
         public:
            static auto applyUiElementTransform(const UiElement&) -> void;
            static auto drawUiElement(const UiElement&) -> void;
            static auto checkByPointInclude(const UiElement&, int, int) -> bool;

         private:
            UiElementSystem();
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
