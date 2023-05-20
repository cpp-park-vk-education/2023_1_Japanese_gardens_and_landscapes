#pragma once

#include <string>
#include <unordered_map>
#include "Event.hpp"
#include "EventListener.hpp"
#include "Entity.hpp"
#include <queue>

namespace AnimeDefendersEngine {

    class EventManager {
     public:
        auto update() -> void;
        static auto addListener(Entity* ent, IEventListener* listener) -> void;
        static auto removeListener(Entity* ent, IEventListener* listener) -> void;
        static auto dispatch(Event& event) -> void;
        static auto addEvent(Event& event) ->void;

     private:
        static std::unordered_map<Entity*, IEventListener*> eventListeners;
        static inline std::priority_queue<Event&> eventQueue{};
    };

}  // namespace AnimeDefendersEngine
