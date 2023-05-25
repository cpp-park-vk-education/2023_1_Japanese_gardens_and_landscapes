#include "EventListener.hpp"

namespace AnimeDefendersEngine {

    auto EventListener::operator==(const EventListener& rhs) const-> bool {
        return (*this).getName() == rhs.getName();
    }

    auto EventListener::getName() const -> const std::string& {
        return m_eventListenerName;
    }

    auto EventListener::getFunction() -> std::function<void()> {
        return m_listenerFunction;
    }

}  // namespace AnimeDefendersEngine::EventManager
