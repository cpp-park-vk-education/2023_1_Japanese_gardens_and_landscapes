#pragma once

#include "UiElementSystem.hpp"
#include "UiLabel.hpp"

namespace AnimeDefendersEngine {
    namespace Graphics {

        class UiLabelSystem : public UiElementSystem {
         public:
            static auto applyUiElementTransform(const UiLabel&) -> void;
            static auto drawUiElement(const UiLabel&) -> void;
            static auto checkByPointInclude(const UiLabel&, int, int) -> bool;

         private:
            UiLabelSystem();
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
