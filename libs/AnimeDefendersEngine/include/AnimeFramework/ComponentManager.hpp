#pragma once

#include "MemoryMaster.hpp"

#include <typeindex>
#include <unordered_map>
#include <vector>

namespace AnimeDefendersEngine {
    class Component;

    class ComponentManager {
     public:
        ~ComponentManager();
        void addComponent(std::type_index typeId, Component* component);
        void deleteComponent(std::type_index typeId, Component* compoment);
        auto getComponents(std::type_index typeId) -> std::vector<Component*>;

     private:
        std::unordered_map<std::type_index, std::vector<Component*>> m_components;
    };
}  // namespace AnimeDefendersEngine
