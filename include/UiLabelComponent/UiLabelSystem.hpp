#pragma ones

#include "System.hpp"
#include "UiLabelElement.hpp"

class UiLabelElementSystem : public System {
 public:
    UiLabelElementSystem() = 0;

    static auto applyUiElementTransform(UiLabelElement*) -> void;
    static auto drawUiElement(UiLabelElement*) -> void;
    static auto checkByPointInclude(UiLabelElement*, int, int) -> bool;
};
