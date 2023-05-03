#pragma ones

#include "System.hpp"
#include "UiColorElement.hpp"

class UiColorElementSystem : public System {
public:
  UiColorElementSystem() = 0;

  static auto applyUiElementTransform(UiColorElement *) -> void;
  static auto drawUiElement(UiColorElement *) -> void;
  static auto checkByPointInclude(UiColorElement *, int, int) -> bool;
};
