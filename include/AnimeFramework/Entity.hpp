#pragma once

#include "Component.hpp"

#include <string>
#include <vector>

namespace AnimeDefendersEngine {

    class Entity {
     public:
        auto addComponent(Component* component) -> void;
        auto getComponent(ComponentType componentType) -> Component*;

     private:
        std::string m_entityId;
        std::vector<Component*> m_entityComponents;
    };

}  // namespace AnimeDefendersEngine
