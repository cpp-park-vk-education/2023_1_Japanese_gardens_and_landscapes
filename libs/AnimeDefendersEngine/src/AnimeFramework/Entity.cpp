#include "Entity.hpp"
#include "Scene.hpp"

using namespace AnimeDefendersEngine;

auto Entity::destroy() -> void {
    m_scene.destroyEntity(m_entityId);
}

Entity::Entity(const std::string& id, Scene& scene) : m_entityId{id}, m_scene{scene} {}

auto Entity::getId() -> std::string const {
    return m_entityId;
}
