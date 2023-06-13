#pragma once

#include "UiColorElement.hpp"
#include "UiElementSystem.hpp"

namespace AnimeDefendersEngine {
    namespace Graphics {

        class UiColorElementSystem : public UiElementSystem {
         public:
            static auto applyUiElementTransform(const UiColorElement&) -> void;
            static auto drawUiElement(const UiColorElement&) -> void;
            static auto checkByPointInclude(const UiColorElement&, int, int) -> bool;

         private:
            UiColorElementSystem();
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
