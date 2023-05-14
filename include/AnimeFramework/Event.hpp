#pragma once

#include <string>

namespace AnimeDefendersEngine {

    enum class EventType {
    };

    class Event {
     private:
        std::string m_name;
        std::string m_additional;
        EventType m_eventType;
    };

}  // namespace AnimeDefendersEngine
