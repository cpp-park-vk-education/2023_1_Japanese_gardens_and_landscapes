#pragma once

#include "Event.hpp"
#include "EventManager.hpp"
#include "GL/glut.h"
#include "Window.hpp"

namespace AnimeDefendersEngine {
    namespace InputManager {
        auto keyboardHandler(unsigned char key, int x, int y) -> void;
        auto motionHandler(int x, int y) -> void;
        auto mouseHandler(int, int, int, int) -> void;
        auto initInputManager(Graphics::Window& window) -> void;
    }  // namespace InputManager
}  // namespace AnimeDefendersEngine
