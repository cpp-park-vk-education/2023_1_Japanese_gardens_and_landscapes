#include "UiColorElement.hpp"

using namespace AnimeDefendersEngine;

auto UiColorElement::applyUiElementTransform() -> void const {}

auto UiColorElement::drawUiElement() -> void const {}

auto UiColorElement::checkByPointInclude(int, int) -> bool const {}

auto UiColorElement::setPosition(int, int) -> void {}

auto UiColorElement::setWidth(int) -> void {}

auto UiColorElement::setHeidth(int) -> void {}

auto UiColorElement::setEventOnClick(std::function<void(void*)>) -> void {}

auto UiColorElement::setColor(Color) -> void {}