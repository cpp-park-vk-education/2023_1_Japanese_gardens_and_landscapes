#pragma ones

#include "UiElement.hpp"

namespace AnimeDefendersEngine {
    namespace Graphics {

        class IUiContextWrapper {
         public:
            virtual auto applyUiViewPort(UiElement&) -> void const = 0;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
