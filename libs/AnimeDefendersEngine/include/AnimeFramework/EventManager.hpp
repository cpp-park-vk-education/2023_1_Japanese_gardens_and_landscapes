#pragma once

#include <map>
#include <string>
#include "Event.hpp"
#include "EventListener.hpp"

namespace AnimeDefendersEngine {

    class EventManager {
     public:
        auto addListener(IEventListener& listener) -> void;
        auto removeListener(IEventListener& listener) -> void;

     private:
        std::map<IEventListener*, IEventListener*> eventListeners;
    };

}  // namespace AnimeDefendersEngine
