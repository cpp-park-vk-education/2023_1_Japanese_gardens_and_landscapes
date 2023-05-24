#include "EventListener.hpp"

namespace AnimeDefendersEngine::EventManager {

    auto EventListener::getName() const -> const std::string& {
        return eventListenerName;
    };
    auto EventListener::getFunction() -> std::function<void()> {
        return listenerFunction;
    }
}  // namespace AnimeDefendersEngine::EventManager
