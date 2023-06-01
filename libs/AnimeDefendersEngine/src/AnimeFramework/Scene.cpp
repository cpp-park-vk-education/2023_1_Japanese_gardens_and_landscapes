#include "Scene.hpp"
#include "ComponentManager.hpp"
#include "Entity.hpp"

namespace AnimeDefendersEngine {

    Scene::Scene(std::size_t sceneId) : m_sceneId{sceneId}, m_componentManager{sceneId} {}

    auto Scene::destroyEntity(const std::string& entityId) -> void {
        m_entityIdsToDestroy.push_back(entityId);
    }

    [[nodiscard]] auto Scene::getComponentManager() -> ComponentManager& {
        return m_componentManager;
    }

    auto Scene::updateScene() -> void {
        for (const auto& entityId : m_entityIdsToDestroy) {
            m_entities.erase(entityId);
        }
        m_entityIdsToDestroy.clear();

        for (const auto& [entityId, entity] : m_entities) {
            entity->update();
        }
    }

    [[nodiscard]] auto Scene::getSceneId() const noexcept -> Scene::IdType {
        return m_sceneId;
    }

    auto Scene::addEntity(std::shared_ptr<Entity> entity) -> void {
        m_entities[entity->getId()] = entity;
    }

}  // namespace AnimeDefendersEngine
