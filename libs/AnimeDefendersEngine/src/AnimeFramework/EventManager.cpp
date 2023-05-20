#include "EventManager.hpp"
#include <memory>

using namespace AnimeDefendersEngine;

auto EventManager::hasEvent(std::string eventName) -> bool
{
    for (const auto& event: eventQueue)
    {
        if (event->getName() == eventName)
        {
            return true;
        }
    }
    return false;
};

auto EventManager::addListener(Entity* ent, IEventListener* listener) -> void{
    eventListeners.push_back(listener);
};

auto EventManager::removeListener(Entity* ent, IEventListener* listener) -> void{
    eventListeners.erase(std::find(eventListeners.begin(), eventListeners.end(), listener));
};

auto EventManager::addEvent(std::unique_ptr<Event>&& event) -> void {
    eventQueue.push_back(std::move(event));
}

auto EventManager::dispatch(std::unique_ptr<Event>&& event) -> void {
    
}
