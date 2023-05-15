#pragma once

#include "UiElement.hpp"

namespace AnimeDefendersEngine {
    namespace Graphics {

        class IUiContextWrapper {
         public:
            virtual auto applyUiViewPort(const UiElement&) -> void = 0;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
