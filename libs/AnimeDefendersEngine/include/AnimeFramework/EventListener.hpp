#pragma once
#include "Event.hpp"

namespace AnimeDefendersEngine {
    class IEventListener {
     public:
        virtual auto onEvent(Event event) -> void = 0;
    };
    class EventListener : public IEventListener {
     public:
        auto onEvent(Event event) -> void override;
    };
}  // namespace AnimeDefendersEngine