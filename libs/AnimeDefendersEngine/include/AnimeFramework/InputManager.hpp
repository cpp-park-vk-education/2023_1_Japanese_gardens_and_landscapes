#pragma once

#include "GL/glut.h"
#include "EventManager.hpp"
#include "Window.hpp"
#include "Event.hpp"

namespace AnimeDefendersEngine {
namespace InputManager
{
    auto keyboardHandler(unsigned char key, int x, int y) -> void;
      auto initInputManager(Graphics::Window& window) -> void;
    }
}  // namespace AnimeDefendersEngine
