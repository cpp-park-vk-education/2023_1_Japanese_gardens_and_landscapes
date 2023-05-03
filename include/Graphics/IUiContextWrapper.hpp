#pragma ones

#include "UiElement.hpp"

class IUiContextWrapper {
public:
  virtual auto applyUiViewPort(UiElement *) -> void = 0;
};
