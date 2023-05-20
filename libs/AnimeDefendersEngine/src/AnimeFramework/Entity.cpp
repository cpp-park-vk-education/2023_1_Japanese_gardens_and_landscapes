#include "Entity.hpp"
#include "Scene.hpp"

using namespace AnimeDefendersEngine;

auto Entity::destroy() -> void {
    m_scene.destroyEntity(m_entityId);
}
