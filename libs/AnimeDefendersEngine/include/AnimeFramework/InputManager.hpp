#pragma once

#include "EventManager.hpp"
#include "Window.hpp"

namespace AnimeDefendersEngine {

    class InputManager {
     public:
        explicit InputManager(Graphics::Window&);
        auto setEventManager(EventManager eventManager) -> void;

     private:
        EventManager m_events;
        Graphics::Window& m_window;
    };

}  // namespace AnimeDefendersEngine