#include "ComponentManager.hpp"
#include "Component.hpp"
#include "MemoryMaster.hpp"

#include <unordered_map>
#include <vector>

using namespace AnimeDefendersEngine;

void ComponentManager::addComponent(std::type_index typeId, Component* component) {
    m_components[typeId].emplace_back(component);
}

auto ComponentManager::getComponents(std::type_index typeId) -> std::vector<Component*> {
    return m_components[typeId];
}
