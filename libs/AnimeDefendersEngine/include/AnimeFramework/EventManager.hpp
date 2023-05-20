#pragma once

#include <memory>
#include <queue>
#include <string>
#include <unordered_map>
#include "Entity.hpp"
#include "Event.hpp"
#include "EventListener.hpp"

namespace AnimeDefendersEngine {

    class EventManager {
     public:
        static auto update() -> void;
        static auto addListener(Entity* ent, IEventListener* listener) -> void;
        static auto removeListener(Entity* ent, IEventListener* listener) -> void;
        static auto dispatch(std::unique_ptr<Event>&& event) -> void;
        static auto addEvent(std::unique_ptr<Event>&& event) -> void;

     private:
        // static std::unordered_map<Entity*, IEventListener*> eventListeners;
        static inline std::priority_queue<std::unique_ptr<Event>> eventQueue{};
    };

}  // namespace AnimeDefendersEngine
