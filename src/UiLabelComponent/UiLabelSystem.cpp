#include "UiLabelSystem.hpp"

using namespace AnimeDefendersEngine::Graphics;

auto UiLabelSystem::applyUiElementTransform(const UiLabel&) -> void {}

auto UiLabelSystem::drawUiElement(const UiLabel&) -> void {}

auto UiLabelSystem::checkByPointInclude(const UiLabel&, int, int) -> bool {
    return false;
}
