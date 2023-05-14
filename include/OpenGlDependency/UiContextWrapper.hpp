#pragma once

#include "IUiContextWrapper.hpp"

namespace AnimeDefendersEngine {
    namespace Graphics {

        class UiContextWrapper : public IUiContextWrapper {
         public:
            auto applyUiViewPort(UiElement&) -> void const override;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
