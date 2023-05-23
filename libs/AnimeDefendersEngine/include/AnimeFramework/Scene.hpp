#pragma once

#include "ComponentManager.hpp"
#include "Entity.hpp"

#include <memory>
#include <string>
#include <vector>

namespace AnimeDefendersEngine {

    class Scene {
     public:
        auto addEntity(std::shared_ptr<Entity>) -> void;
        auto deleteEntity(std::string entityId) -> void;

     private:
        std::vector<std::shared_ptr<Entity>> m_entities;
        std::shared_ptr<ComponentManager> m_components;
        int m_sceneId{};
    };

}  // namespace AnimeDefendersEngine
