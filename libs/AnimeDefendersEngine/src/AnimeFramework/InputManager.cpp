#include "InputManager.hpp"

namespace AnimeDefendersEngine {

    auto InputManager::keyboardHandler(unsigned char pressedKey, int xMousePosition, int yMousePosition) -> void {
        auto event = std::make_unique<Event>("Key" + pressedKey, EventType::KeyPressed);
        EventManager::getInstance().addEvent(std::move(event));
    }

    auto InputManager::passiveMotionHandler(int xMousePosition, int yMousePosition) -> void {}

    auto InputManager::motionHandler(int xMousePosition, int yMousePosition) -> void {}

    auto InputManager::mouseHandler(int button, int buttonState, int xMousePosition, int yMousePosition) -> void {
        switch (button) {
            case GLUT_LEFT_BUTTON:
                if (state == GLUT_DOWN) {
                };
                break;
            case GLUT_MIDDLE_BUTTON:
                if (state == GLUT_DOWN) {
                    ;
                }
                break;
            case GLUT_RIGHT_BUTTON:
                if (state == GLUT_DOWN) {
                };
                break;
            default:
                break;
        }
    }

    auto InputManager::initInputManager(Graphics::Window& window) -> void {
        window.setWindowKeyboardListener(keyboardHandler);
        window.setWindowMouseListener(mouseHandler);
        window.setWindowMotionListener(motionHandler);
    }

    auto InputManager::getButtonDown(unsigned char button) -> bool {
        return EventManager::getInstance().hasEvent("Key" + button);
    }
}  // namespace AnimeDefendersEngine
