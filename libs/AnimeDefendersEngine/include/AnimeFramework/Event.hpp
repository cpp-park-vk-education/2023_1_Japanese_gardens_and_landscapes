#pragma once

#include <string>

namespace AnimeDefendersEngine {

    enum class EventType : unsigned char {
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
     public:
        Event() = default;
        Event(const std::string& name, EventType type, const std::string& add) : m_name(name), m_eventType(type), m_additional(add) {}
        auto getType() const -> EventType { return m_eventType; }
        auto getName() const -> const std::string& { return m_name; }

     private:
        std::string m_name;
        std::string m_additional;
        EventType m_eventType{};
    };

}  // namespace AnimeDefendersEngine
