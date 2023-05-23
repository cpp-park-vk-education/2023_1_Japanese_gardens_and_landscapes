#include "Entity.hpp"

using namespace AnimeDefendersEngine;

auto Entity::addComponent(Component*) -> void {}

auto Entity::getComponent(std::type_index) -> Component* {
    return nullptr;
}
