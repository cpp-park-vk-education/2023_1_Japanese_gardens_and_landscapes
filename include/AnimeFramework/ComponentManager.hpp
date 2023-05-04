#pragma once

#include "Component.hpp"
#include "MemoryMaster.hpp"

#include <unordered_map>
#include <vector>

namespace AnimeDefendersEngine {

    class IComponentManager {
     public:
        virtual void addComponent(ComponentType typeId, Component* component) = 0;
        virtual auto getComponents(ComponentType typeId) -> std::vector<Component*> = 0;
    };

    class ComponentManager : public IComponentManager {
     public:
        void addComponent(ComponentType typeId, Component* component) override;
        auto getComponents(ComponentType typeId) -> std::vector<Component*> override;

     private:
        std::unordered_map<ComponentType, std::vector<Component*>> m_components;
    };
}  // namespace AnimeDefendersEngine