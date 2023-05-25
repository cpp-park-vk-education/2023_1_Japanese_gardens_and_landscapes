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
        static InputManager& getInstance() {
            static InputManager instance;
            return instance;
        }
        InputManager(InputManager const&) = delete;
        void operator=(InputManager const&) = delete;
        auto keyboardHandler(unsigned char pressedKey, int xMousePosition, int yMousePosition) -> void;
        auto passiveMotionHandler(int xMousePosition, int yMousePosition) -> void;
        auto motionHandler(int xMousePosition, int yMousePosition) -> void;
        auto mouseHandler(int button, int buttonState, int xMousePosition, int yMousePosition) -> void;
        auto initInputManager(Graphics::Window& window) -> void;
        auto getButtonDown(unsigned char button) -> bool;

     private:
        InputManager() {}
        InputManager(InputManager const&);
        void operator=(InputManager const&);
    };
}  // namespace AnimeDefendersEngine
