#pragma once

#include <functional>
#include <memory>
#include <string>
#include <vector>
#include "Entity.hpp"
#include "Event.hpp"

namespace AnimeDefendersEngine {
    namespace EventManager {

        class EventListener {
         public:
            explicit EventListener(const std::function<void()>& function, const std::string& name)
                : listenerFunction(function), eventListenerName(name) {}
            auto getName() const -> std::string { return eventListenerName; }
            auto function() -> std::function<void()> { return listenerFunction; }
            friend bool operator==(const EventListener& lhs, const EventListener& rhs);

         private:
            std::string eventListenerName;
            std::function<void()> listenerFunction;
        };

        bool operator==(const EventListener& lhs, const EventListener& rhs) {
            return lhs.getName() == rhs.getName();
        }

        auto update() -> void;
        auto addListener(const EventListener& listener) -> void;
        auto removeListener(const EventListener& listener) -> void;
        auto dispatch(std::unique_ptr<Event> event) -> void;
        auto addEvent(std::unique_ptr<Event> event) -> void;
        auto hasEvent(const std::string& eventName) -> bool;

        std::vector<EventListener> eventListeners{};
        std::vector<std::unique_ptr<Event>> eventQueue{};
    }  // namespace EventManager
}  // namespace AnimeDefendersEngine
