#include "Scene.hpp"
#include "ComponentManager.hpp"

using namespace AnimeDefendersEngine;

Scene::Scene(int id) : m_sceneId{id} {}

auto Scene::destroyEntity(const std::string& entityId) -> void {
    m_entityIdsToDestroy.push_back(entityId);
}

[[nodiscard]] auto Scene::getComponentManager() -> ComponentManager& {
    return m_componentManager;
}

auto Scene::updateScene() -> void {
    for (const auto& id : m_entityIdsToDestroy) {
        m_entities.erase(id);
    }
    m_entities.clear();
}

[[nodiscard]] auto Scene::getSceneId() const noexcept -> int {
    return m_sceneId;
}
