#pragma once

#include <string>
#include <typeindex>

namespace AnimeDefendersEngine {

    class Component {
     public:
        explicit Component(const std::string& entityId);

        [[nodiscard]] auto getEntityId() const noexcept -> const std::string&;

     private:
        std::string m_entityId;
    };

}  // namespace AnimeDefendersEngine
