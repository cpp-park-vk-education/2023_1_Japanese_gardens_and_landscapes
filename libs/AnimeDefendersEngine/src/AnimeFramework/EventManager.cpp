#include "EventManager.hpp"
#include <memory>

using namespace AnimeDefendersEngine;

auto EventManager::hasEvent(std::string eventName) -> bool {
    for (const auto& event : eventQueue) {
        if (event->getName() == eventName) {
            return true;
        }
    }
    return false;
};

auto EventManager::update() -> void {
    for (auto& event : eventQueue) {
        EventManager::dispatch(std::move(event));
    }
}

auto EventManager::addListener(Entity* ent, IEventListener* listener) -> void {
    eventListeners.push_back(listener);
};

auto EventManager::removeListener(Entity* ent, IEventListener* listener) -> void {
    eventListeners.erase(std::find(eventListeners.begin(), eventListeners.end(), listener));
};

auto EventManager::addEvent(std::unique_ptr<Event>&& event) -> void {
    eventQueue.emplace(eventQueue.begin(), std::move(event));
}

auto EventManager::dispatch(std::unique_ptr<Event>&& event) -> void {
    for (auto listener : eventListeners) {
        listener->onEvent(*event);
    }
}
