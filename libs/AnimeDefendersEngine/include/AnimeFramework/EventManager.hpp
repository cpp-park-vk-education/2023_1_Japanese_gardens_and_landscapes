#pragma once

#include <functional>
#include <memory>
#include <string>
#include <vector>
#include "Entity.hpp"
#include "Event.hpp"
#include "EventListener.hpp"

namespace AnimeDefendersEngine {

    class EventManager {
     public:
        auto update() -> void;
        auto addListener(const EventListener& listener) -> void;
        auto removeListener(const EventListener& listener) -> void;
        auto dispatch(std::unique_ptr<Event> event) -> void;
        auto addEvent(std::unique_ptr<Event> event) -> void;
        [[nodiscard]] auto hasEvent(const std::string& eventName) -> bool;

     private:
        std::vector<EventListener> m_eventListeners{};
        std::vector<std::unique_ptr<Event>> m_eventQueue{};
    };
}  // namespace AnimeDefendersEngine
