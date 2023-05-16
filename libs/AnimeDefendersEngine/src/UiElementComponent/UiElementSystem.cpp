#include "UiElementSystem.hpp"

using namespace AnimeDefendersEngine::Graphics;

auto UiElementSystem::applyUiElementTransform(const UiElement&) -> void {}

auto UiElementSystem::drawUiElement(const UiElement&) -> void {}

auto UiElementSystem::checkByPointInclude(const UiElement&, int, int) -> bool {
    return false;
}
