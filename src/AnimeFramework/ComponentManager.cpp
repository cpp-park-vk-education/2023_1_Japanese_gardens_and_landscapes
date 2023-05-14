#include "Component.hpp"
#include "ComponentManager.hpp"
#include "MemoryMaster.hpp"

#include <unordered_map>
#include <vector>

using namespace AnimeDefendersEngine;

void ComponentManager::addComponent(ComponentType typeId, Component* component) {}

auto ComponentManager::getComponents(ComponentType typeId) -> std::vector<Component*> {}
