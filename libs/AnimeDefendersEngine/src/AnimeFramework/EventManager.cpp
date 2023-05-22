#include "EventManager.hpp"
#include <memory>

auto AnimeDefendersEngine::EventManager::hasEvent(std::string& eventName) -> bool {
    for (const auto& event : eventQueue) {
        if (event->getName() == eventName) {
            return true;
        }
    }
    return false;
}

auto AnimeDefendersEngine::EventManager::update() -> void {
    for (auto& event : eventQueue) {
        EventManager::dispatch(std::move(event));
    }
    eventQueue.clear();
}

auto AnimeDefendersEngine::EventManager::addListener(std::function<void()>& listener) -> void {
    eventListeners.push_back(listener);
};

auto AnimeDefendersEngine::EventManager::removeListener(std::function<void()>& listener) -> void {
    eventListeners.erase(std::find(eventListeners.begin(), eventListeners.end(), listener));
};

auto AnimeDefendersEngine::EventManager::addEvent(std::unique_ptr<Event>&& event) -> void {
    eventQueue.emplace(eventQueue.begin(), std::move(event));
}

auto AnimeDefendersEngine::EventManager::dispatch(std::unique_ptr<Event>&& event) -> void {
    for (const auto& listener : eventListeners) {
        listener();
    }
}
