#include "UiTextureElement.hpp"

using namespace AnimeDefendersEngine::Graphics;

auto UiTextureElement::applyUiElementTransform() -> void {}

auto UiTextureElement::drawUiElement() -> void {}

auto UiTextureElement::checkByPointInclude(int, int) -> bool {
    return false;
}

auto UiTextureElement::setPosition(int, int) -> void {}

auto UiTextureElement::setWidth(int) -> void {}

auto UiTextureElement::setHeidth(int) -> void {}

auto UiTextureElement::setEventOnClick(std::function<void(int, int, int)>) -> void {}

auto UiTextureElement::setTexture(Texture) -> void {}
