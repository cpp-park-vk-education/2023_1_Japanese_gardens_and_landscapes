#pragma ones

#include "System.hpp"
#include "UiElement.hpp"

class UiElementSystem : public System {
public:
  UiElementSystem() = 0;

  static auto applyUiElementTransform(UiElement *) -> void;
  static auto drawUiElement(UiElement *) -> void;
  static auto checkByPointInclude(UiElement *, int, int) -> bool;
};
