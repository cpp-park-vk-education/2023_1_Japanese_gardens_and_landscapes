#include "EventManager.hpp"
#include <memory>

using namespace AnimeDefendersEngine;

auto EventManager::addListener(Entity* ent, IEventListener* listener) -> void{
    // eventListeners.insert({ent, listener});
};

auto EventManager::removeListener(Entity* ent, IEventListener* listener) -> void{
    // eventListeners.erase(ent);
};

auto EventManager::addEvent(std::unique_ptr<Event>&& event) -> void {
    eventQueue.push(event);
}

auto EventManager::dispatch(std::unique_ptr<Event>&& event) -> void {
    // auto it = eventListeners.find(event.getType());
    // if (it != eventListeners.end()) {
    //     for (const auto& listener : it->second) {
    //         listener(event);
    //     }
    // }
}
