#include "UiElement.hpp"

using namespace AnimeDefendersEngine::Graphics;

auto UiElement::applyUiElementTransform() -> void {}

auto UiElement::drawUiElement() -> void {}

auto UiElement::checkByPointInclude(int, int) -> bool {
    return false;
}

auto UiElement::setPosition(int, int) -> void {}

auto UiElement::setWidth(int) -> void {}

auto UiElement::setHeidth(int) -> void {}

auto UiElement::setEventOnClick(std::function<void(int, int, int)>) -> void {}
