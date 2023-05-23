#include "Entity.hpp"
#include "Scene.hpp"

namespace AnimeDefendersEngine {

    auto Entity::destroy() -> void {
        m_scene.destroyEntity(m_entityId);
    }

    Entity::Entity(std::string entityId, Scene& scene) : m_entityId{std::move(entityId)}, m_scene{scene} {}

    [[nodiscard]] auto Entity::getId() const noexcept -> const std::string& {
        return m_entityId;
    }

}  // namespace AnimeDefendersEngine
