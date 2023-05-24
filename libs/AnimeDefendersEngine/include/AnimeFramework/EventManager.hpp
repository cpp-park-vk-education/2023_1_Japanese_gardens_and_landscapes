#pragma once

#include "Event.hpp"

#include <queue>
#include <string>

namespace AnimeDefendersEngine {

    class IEventManager {
     public:
        auto hasEvent(std::string eventName) -> bool;
    };

    class EventManager : public IEventManager {
     public:
        static auto hasEvent(std::string eventName) -> bool;
        static auto update() -> void;

     private:
        std::priority_queue<Event> m_events;
    };

}  // namespace AnimeDefendersEngine