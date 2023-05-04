#include "UiLabel.hpp"

using namespace AnimeDefendersEngine;

auto UiLabel::applyUiElementTransform() -> void const {}

auto UiLabel::drawUiElement() -> void const {}

auto UiLabel::checkByPointInclude(int, int) -> bool const {}

auto UiLabel::setPosition(int, int) -> void {}

auto UiLabel::setWidth(int) -> void {}

auto UiLabel::setHeidth(int) -> void {}

auto UiLabel::setEventOnClick(std::function<void(void*)>) -> void {}

auto UiLabel::setTextContent(const std::string&) -> void {}

auto UiLabel::setTextColor(Color) -> void {}
