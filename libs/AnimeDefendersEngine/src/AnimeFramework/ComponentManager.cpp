#include "ComponentManager.hpp"
#include "Component.hpp"
#include "MemoryMaster.hpp"

#include <unordered_map>
#include <vector>

using namespace AnimeDefendersEngine;

void ComponentManager::addComponent(ComponentType, Component*) {}

auto ComponentManager::getComponents(ComponentType) -> std::vector<Component*> {
    return {};
}
