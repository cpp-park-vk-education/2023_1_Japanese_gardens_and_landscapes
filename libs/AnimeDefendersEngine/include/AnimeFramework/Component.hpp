#pragma once

#include <string>
#include <typeindex>

namespace AnimeDefendersEngine {

    class Component {
     public:
        explicit Component(const std::string& entityId) : m_entityId{entityId} {}

        [[nodiscard]] auto getEntityId() const noexcept -> std::string { return m_entityId; }

     private:
        std::string m_entityId;
    };

}  // namespace AnimeDefendersEngine
