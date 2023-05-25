#include "EventListener.hpp"

namespace AnimeDefendersEngine {

    auto operator==(const EventListener& lhs, const EventListener& rhs) -> bool {
        return lhs.getName() == rhs.getName();
    }

    auto EventListener::getName() const -> const std::string& {
        return m_eventListenerName;
    }

    auto EventListener::getFunction() -> std::function<void()> {
        return m_listenerFunction;
    }

}  // namespace AnimeDefendersEngine::EventManager
