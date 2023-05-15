#include "UiTextureElementSystem.hpp"

using namespace AnimeDefendersEngine::Graphics;

auto UiTextureElementSystem::applyUiElementTransform(const UiTextureElement&) -> void {}

auto UiTextureElementSystem::drawUiElement(const UiTextureElement&) -> void {}

auto UiTextureElementSystem::checkByPointInclude(const UiTextureElement&, int, int) -> bool {
    return false;
}
