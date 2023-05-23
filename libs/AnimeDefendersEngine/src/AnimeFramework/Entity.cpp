#include "Entity.hpp"
#include "Scene.hpp"

using namespace AnimeDefendersEngine;

auto Entity::destroy() -> void {
    m_scene.destroyEntity(m_entityId);
}

Entity::Entity(const std::string& id, Scene& scene) : m_entityId{id}, m_scene{scene} {}

[[nodiscard]] auto Entity::getId() const noexcept -> const std::string& {
    return m_entityId;
}
