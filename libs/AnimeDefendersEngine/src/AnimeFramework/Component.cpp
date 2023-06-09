#include "Component.hpp"

using namespace AnimeDefendersEngine;

[[nodiscard]] auto Component::getEntityId() const noexcept -> const std::string& {
    return m_entityId;
}

Component::Component(const std::string& entityId) : m_entityId{entityId} {}
