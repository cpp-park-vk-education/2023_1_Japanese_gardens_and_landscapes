#pragma once

#include <string>

namespace AnimeDefendersEngine {

    enum class EventType {
        None = 0,
        KeyPressed,
        KeyReleased,
        OnKeyDown,
        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,
        MouseScrolled
    };

    class Event {
     private:
        std::string m_name;
        std::string m_additional;
        EventType m_eventType;
    };

}  // namespace AnimeDefendersEngine
