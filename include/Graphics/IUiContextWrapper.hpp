#pragma ones

#include "UiElement.hpp"

namespace AnimeDefendersEngine {

    class IUiContextWrapper {
     public:
        virtual auto applyUiViewPort(UiElement*) -> void const = 0;
    };

}  // namespace AnimeDefendersEngine
