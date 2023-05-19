#include "Component.hpp"

using namespace AnimeDefendersEngine;

[[nodiscard]] auto Component::getEntityId() const noexcept -> std::string {git 
    return m_entityId;
}

Component::Component(const std::string& entityId) : m_entityId{entityId} {}
