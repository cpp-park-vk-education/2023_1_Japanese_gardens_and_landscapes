#pragma once

#include "IUiContextWrapper.hpp"

namespace AnimeDefendersEngine {

    class UiContextWrapper : public IUiContextWrapper {
     public:
        auto applyUiViewPort(UiElement*) -> void const override;
    };

}  // namespace AnimeDefendersEngine
