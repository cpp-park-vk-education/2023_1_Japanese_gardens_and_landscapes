#pragma once

#include <GL/glut.h>

#include "Event.hpp"
#include "EventManager.hpp"
#include "Window.hpp"

namespace AnimeDefendersEngine {

    struct MousePosition {
        MousePosition() = default;
        MousePosition(int x, int y) : x(x), y(y) {}
        int x{0};
        int y{0};
    };

    class InputManager {
     public:
        InputManager(EventManager& eventManager, Graphics::Window& window) : m_eventManager(eventManager) {
            window.setWindowKeyboardListener(keyboardHandler);
            window.setWindowMouseListener(mouseHandler);
            window.setWindowMotionListener(motionHandler);
        }
        auto keyboardHandler(unsigned char pressedKey, int xMousePosition, int yMousePosition) -> void;
        auto passiveMotionHandler(int xMousePosition, int yMousePosition) -> void;
        auto motionHandler(int xMousePosition, int yMousePosition) -> void;
        auto mouseHandler(int button, int buttonState, int xMousePosition, int yMousePosition) -> void;
        auto getButtonDown(unsigned char button) -> bool;

     private:
        EventManager m_eventManager;
    };
}  // namespace AnimeDefendersEngine
