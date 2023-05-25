#include "EventManager.hpp"
#include <memory>

namespace AnimeDefendersEngine {

    auto EventManager::hasEvent(const std::string& eventName) -> bool {
        for (const auto& event : eventQueue) {
            if (event->getName() == eventName) {
                return true;
            }
        }
        return false;
    }

    auto EventManager::update() -> void {
        for (auto& event : eventQueue) {
            dispatch(std::move(event));
        }
        eventQueue.clear();
    }

    auto EventManager::addListener(const EventListener& listener) -> void {
        eventListeners.push_back(listener);
    };

    auto EventManager::removeListener(const EventListener& listener) -> void {
        std::erase(eventListeners, listener);
    };

    auto EventManager::addEvent(std::unique_ptr<Event> event) -> void {
        eventQueue.emplace(eventQueue.begin(), std::move(event));
    }

    auto EventManager::dispatch(std::unique_ptr<Event> event) -> void {
        for (auto& listener : eventListeners) {
            listener.getFunction()();
        }
    }

}  // namespace AnimeDefendersEngine
