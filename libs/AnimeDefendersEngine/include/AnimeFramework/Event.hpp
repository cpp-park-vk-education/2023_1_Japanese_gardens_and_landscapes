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

     public:
        Event(std::string name, EventType type, std::string add = "") : m_name(name), m_eventType(type), m_additional(add) {}
        auto getType() -> EventType { return m_eventType; }
        auto getName() -> std::string { return m_name; }
    };

}  // namespace AnimeDefendersEngine
