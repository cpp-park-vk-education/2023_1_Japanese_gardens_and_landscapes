#pragma once

#include <string>
#include <unordered_map>
#include "Event.hpp"
#include "EventListener.hpp"
#include "Entity.hpp"

namespace AnimeDefendersEngine {

    class EventManager {
     public:
        auto update() -> void;
        auto addListener(Entity* ent, IEventListener* listener) -> void;
        auto removeListener(Entity* ent, IEventListener* listener) -> void;
        auto dispatch(Event& event) const -> void;

     private:
        std::unordered_map<Entity*, IEventListener*> eventListeners;
    };

}  // namespace AnimeDefendersEngine
