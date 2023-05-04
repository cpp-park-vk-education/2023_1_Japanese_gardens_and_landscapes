#pragma once

#include "EventManager.hpp"
#include "Window.hpp"

namespace AnimeDefenders {
class InputManager {
 public:
    auto setEventManager(EventManager eventManager) -> void;

 private:
    EventManager m_events;
    Window& m_window;
};
}  // namespace AnimeDefenders