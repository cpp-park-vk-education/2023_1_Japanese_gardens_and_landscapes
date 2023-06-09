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
        Event(const std::string& name, EventType type, const std::string& additionalInfo = "")
            : m_name(name), m_eventType(type), m_additional(additionalInfo) {}
        [[nodiscard]] auto getType() const -> EventType { return m_eventType; }
        [[nodiscard]] auto getName() const -> const std::string& { return m_name; }

     private:
        std::string m_name;
        std::string m_additional;
        EventType m_eventType{EventType::None};
    };

}  // namespace AnimeDefendersEngine
