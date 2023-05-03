#pragma ones

#include "System.hpp"
#include "UiTextureElement.hpp"

class UiTextureElementSystem : public System {
public:
  UiTextureElementSystem() = 0;

  static auto applyUiElementTransform(UiTextureElement *) -> void;
  static auto drawUiElement(UiTextureElement *) -> void;
  static auto checkByPointInclude(UiTextureElement *, int, int) -> bool;
};
