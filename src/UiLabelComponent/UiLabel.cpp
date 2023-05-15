#include "UiLabel.hpp"

using namespace AnimeDefendersEngine::Graphics;

auto UiLabel::applyUiElementTransform() -> void {}

auto UiLabel::drawUiElement() -> void {}

auto UiLabel::checkByPointInclude(int, int) -> bool {
    return false;
}

auto UiLabel::setPosition(int, int) -> void {}

auto UiLabel::setWidth(int) -> void {}

auto UiLabel::setHeidth(int) -> void {}

auto UiLabel::setEventOnClick(std::function<void(int, int, int)>) -> void {}

auto UiLabel::setTextContent(std::string) -> void {}

auto UiLabel::setTextColor(Color) -> void {}
