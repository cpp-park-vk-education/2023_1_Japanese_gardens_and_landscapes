#pragma ones

#include "UiElement.hpp"

auto UiElement::applyUiElementTransform() -> void {}

auto UiElement::drawUiElement() -> void {}

auto UiElement::checkByPointInclude(int, int) -> bool {}

auto UiElement::setPosition(int, int) -> void {}

auto UiElement::setWidth(int) -> void {}

auto UiElement::setHeidth(int) -> void {}

auto UiElement::setEventOnClick(std::function<void(void *)>) -> void {}

auto UiElement::setTextContent(const std::string &) -> void {}

auto UiElement::setTextColor(Color) -> void {}

auto UiElement::setTextSize(int) -> void {}
