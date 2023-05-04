#include "UiTextureElement.hpp"

using namespace AnimeDefendersEngine;

auto UiTextureElement::applyUiElementTransform() -> void const {}

auto UiTextureElement::drawUiElement() -> void const {}

auto UiTextureElement::checkByPointInclude(int, int) -> bool const {}

auto UiTextureElement::setPosition(int, int) -> void {}

auto UiTextureElement::setWidth(int) -> void {}

auto UiTextureElement::setHeidth(int) -> void {}

auto UiTextureElement::setEventOnClick(std::function<void(void*)>) -> void {}

auto UiTextureElement::setTexture(Texture) -> void {}
