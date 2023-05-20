#include "Scene.hpp"
#include "ComponentManager.hpp"

using namespace AnimeDefendersEngine;

Scene::Scene(int id) : m_sceneId{id} {}

auto Scene::destroyEntity(const std::string& entityId) -> void {
    m_entityIdsToDestroy.push_back(entityId);
}

[[nodiscard]] auto Scene::getComponentManager() -> ComponentManager& {
    return m_components;
}

auto Scene::updateScene() -> void {
    while (!m_entityIdsToDestroy.empty()) {
        const auto& id = m_entityIdsToDestroy.back();
        m_entities.erase(id);
        m_entityIdsToDestroy.pop_back();
    }
}

auto Scene::getSceneId() const noexcept -> int {
    return m_sceneId;
}
