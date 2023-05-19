#pragma once

#include <GLFW/glfw3.h>
#include "EventManager.hpp"
#include "Window.hpp"

namespace AnimeDefendersEngine {

    class InputManager {
     public:
        explicit InputManager(Graphics::Window&);
        auto setEventManager(EventManager eventManager) -> void;
        auto keyCallback() -> void;

     private:
        EventManager m_events;
        Graphics::Window& m_window;
    };

}  // namespace AnimeDefendersEngine
