#pragma once

#include <memory>
#include <queue>
#include <string>
#include <vector>
#include "Entity.hpp"
#include "Event.hpp"

namespace AnimeDefendersEngine {
    namespace EventManager {
        auto update() -> void;
        auto addListener(std::function<void()>& listener) -> void;
        auto removeListener(std::function<void()>& listener) -> void;
        auto dispatch(std::unique_ptr<Event>&& event) -> void;
        auto addEvent(std::unique_ptr<Event>&& event) -> void;
        auto hasEvent(std::string& eventName) -> bool;

        std::vector<std::function<void()>> eventListeners{};
        std::vector<std::unique_ptr<Event>> eventQueue{};
    }  // namespace EventManager
}  // namespace AnimeDefendersEngine
