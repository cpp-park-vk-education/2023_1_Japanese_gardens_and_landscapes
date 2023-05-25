#pragma once

#include <functional>
#include <memory>
#include <string>
#include <vector>
#include "Entity.hpp"
#include "Event.hpp"
#include "EventListener.hpp"

namespace AnimeDefendersEngine {
    // Singleton class
    class EventManager {
     public:
        static EventManager& getInstance() {
            static EventManager instance;
            return instance;
        }
        auto update() -> void;
        auto addListener(const EventListener& listener) -> void;
        auto removeListener(const EventListener& listener) -> void;
        auto dispatch(std::unique_ptr<Event> event) -> void;
        auto addEvent(std::unique_ptr<Event> event) -> void;
        auto hasEvent(const std::string& eventName) -> bool;

     private:
        std::vector<EventListener> eventListeners{};
        std::vector<std::unique_ptr<Event>> eventQueue{};
    };
}  // namespace AnimeDefendersEngine
