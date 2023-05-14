#pragma once

#include "Event.hpp"

#include <queue>
#include <string>

namespace AnimeDefendersEngine {

    class IEventManager {
     public:
        virtual auto hasEvent(std::string eventName) -> bool = 0;
    };

    class EventManager : public IEventManager {
     public:
        auto hasEvent(std::string eventName) -> bool override;

     private:
        std::priority_queue<Event> m_events;
    };

}  // namespace AnimeDefendersEngine
