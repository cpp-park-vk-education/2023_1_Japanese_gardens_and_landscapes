#include "UiColorElementSystem.hpp"

using namespace AnimeDefendersEngine::Graphics;

auto UiColorElementSystem::applyUiElementTransform(const UiColorElement&) -> void {}

auto UiColorElementSystem::drawUiElement(const UiColorElement&) -> void {}

auto UiColorElementSystem::checkByPointInclude(const UiColorElement&, int, int) -> bool {
    return false;
}
