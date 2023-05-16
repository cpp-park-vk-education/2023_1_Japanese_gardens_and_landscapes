#pragma once

#include "MemoryMaster.hpp"

#include <typeindex>
#include <unordered_map>
#include <vector>

namespace AnimeDefendersEngine {
    class Component;

    class IComponentManager {
     public:
        virtual void addComponent(std::type_index typeId, Component* component) = 0;
        virtual void deleteComponent(std::type_index typeId, Component* compoment) = 0;
        virtual auto getComponents(std::type_index typeId) -> std::vector<Component*> = 0;
    };

    class ComponentManager : public IComponentManager {
     public:
        void addComponent(std::type_index typeId, Component* component) override;
        void deleteComponent(std::type_index typeId, Component* compoment) override;
        auto getComponents(std::type_index typeId) -> std::vector<Component*> override;

     private:
        std::unordered_map<std::type_index, std::vector<Component*>> m_components;
    };
}  // namespace AnimeDefendersEngine
