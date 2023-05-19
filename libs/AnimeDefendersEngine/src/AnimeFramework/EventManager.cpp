#include "EventManager.hpp"

using namespace AnimeDefendersEngine;

auto EventManager::addListener(Entity* ent, IEventListener* listener) -> void {
    eventListeners.insert({ent, listener});
};

auto EventManager::removeListener(Entity* ent, IEventListener* listener) -> void {
    eventListeners.erase({ent, listener});
};

auto EventManager::dispatch(Event& event) const -> void {
    auto it = eventListeners.find(event.getType());
    if (it != eventListeners.end()) {
        for (const auto& listener : it->second) {
            listener(event);
        }
    }
}
