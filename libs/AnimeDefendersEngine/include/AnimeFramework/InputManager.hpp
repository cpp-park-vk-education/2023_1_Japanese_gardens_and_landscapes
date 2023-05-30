#pragma once

#include "EventManager.hpp"
#include "Window.hpp"

#include <GL/glut.h>

namespace AnimeDefendersEngine {

    struct MousePosition {
        MousePosition() = default;
        MousePosition(int x, int y) : x(x), y(y) {}
        int x{0};
        int y{0};
    };

    class InputManager {
     public:
        InputManager(EventManager& eventManager, Graphics::Window& window);
        auto keyboardHandler(unsigned char pressedKey, int xMousePosition, int yMousePosition) -> void;
        auto passiveMotionHandler(int xMousePosition, int yMousePosition) -> void;
        auto motionHandler(int xMousePosition, int yMousePosition) -> void;
        auto mouseHandler(int button, int buttonState, int xMousePosition, int yMousePosition) -> void;
        [[nodiscard]] auto getButtonDown(unsigned char button) -> bool;

     private:
        EventManager m_eventManager;
    };
}  // namespace AnimeDefendersEngine
