#pragma ones

#include "UiElement.hpp"

namespace AnimeDefendersEngine {
    namespace Graphics {

        class IUiContextWrapper {
         public:
            virtual auto applyUiViewPort(const UiElement&) -> void const = 0;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
