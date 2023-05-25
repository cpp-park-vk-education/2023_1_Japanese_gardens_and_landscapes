#include <memory>

#include "EventManager.hpp"
#include "EventListener.hpp"
namespace AnimeDefendersEngine {

    auto EventManager::hasEvent(const std::string& eventName) -> bool {
        for (const auto& event : m_eventQueue) {
            if (event->getName() == eventName) {
                return true;
            }
        }
        return false;
    }

    auto EventManager::update() -> void {
        for (auto& event : m_eventQueue) {
            dispatch(std::move(event));
        }
        m_eventQueue.clear();
    }

    auto EventManager::addListener(const EventListener& listener) -> void {
        m_eventListeners.push_back(listener);
    };

    auto EventManager::removeListener(const EventListener& listener) -> void {
        std::erase(m_eventListeners, listener);
    };

    auto EventManager::addEvent(std::unique_ptr<Event> event) -> void {
        m_eventQueue.emplace(m_eventQueue.begin(), std::move(event));
    }

    auto EventManager::dispatch(std::unique_ptr<Event> event) -> void {
        for (auto& listener : m_eventListeners) {
            listener.getFunction()();
        }
    }

}  // namespace AnimeDefendersEngine
