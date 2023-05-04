#pragma once

#include "IUiContextWrapper.hpp"

class UiContextWrapper : public IUiContextWrapper {
    auto applyUiViewPort(UiElement*) -> void override;
};
