#include "Scene.hpp"
#include "ComponentManager.hpp"

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
        m_entities.clear();
    }

    [[nodiscard]] auto Scene::getSceneId() const noexcept -> int {
        return m_sceneId;
    }

}  // namespace AnimeDefendersEngine
