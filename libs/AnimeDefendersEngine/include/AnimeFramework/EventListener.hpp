#pragma once

#include "Event.hpp"

#include <functional>

namespace AnimeDefendersEngine {
    class EventListener {
     public:
        EventListener(const std::function<void()>& function, const std::string& name)
            : m_listenerFunction(function), m_eventListenerName(name) {}
        [[nodiscard]] auto getName() const -> const std::string&;
        [[nodiscard]] auto getFunction() -> std::function<void()>;

     private:
        std::string m_eventListenerName;
        std::function<void()> m_listenerFunction;
    };

}  // namespace AnimeDefendersEngine::EventManager
