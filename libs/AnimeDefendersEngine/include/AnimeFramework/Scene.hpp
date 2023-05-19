#pragma once

#include "ComponentManager.hpp"
#include "Entity.hpp"

#include <memory>
#include <queue>
#include <string>
#include <vector>

namespace AnimeDefendersEngine {

    class Scene {
     public:
        auto addEntity(std::shared_ptr<Entity> entity) -> void { m_entities[entity->getId()] = entity; };
        auto destroyEntity(const std::string& entityId) -> void { m_entityIdsToDestroy.push(entityId); }

        auto updateScene() -> void {
            while (!m_entityIdsToDestroy.empty()) {
                m_entities.erase(m_entityIdsToDestroy.back());
                m_entityIdsToDestroy.pop();
            }
        }

     private:
        std::unordered_map<std::string, std::shared_ptr<Entity>> m_entities;
        ComponentManager m_components;
        int m_sceneId{};
        std::queue<std::string> m_entityIdsToDestroy;
    };

}  // namespace AnimeDefendersEngine
