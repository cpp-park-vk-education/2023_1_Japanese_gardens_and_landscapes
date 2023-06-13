#include "Entity.hpp"

using namespace AnimeDefendersEngine;

auto Entity::addComponent(Component*) -> void {}

auto Entity::getComponent(ComponentType) -> Component* {
    return nullptr;
}
