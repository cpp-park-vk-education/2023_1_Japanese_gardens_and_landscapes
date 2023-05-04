#include "UiElement.hpp"

using namespace AnimeDefendersEngine;

auto UiElement::applyUiElementTransform() -> void const {}

auto UiElement::drawUiElement() -> void const {}

auto UiElement::checkByPointInclude(int, int) -> bool const {}

auto UiElement::setPosition(int, int) -> void {}

auto UiElement::setWidth(int) -> void {}

auto UiElement::setHeidth(int) -> void {}

auto UiElement::setEventOnClick(std::function<void(void*)>) -> void {}
