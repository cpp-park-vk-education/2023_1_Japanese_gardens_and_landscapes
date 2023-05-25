#include "InputManager.hpp"

namespace AnimeDefendersEngine {

    auto InputManager::keyboardHandler(unsigned char pressedKey, int xMousePosition, int yMousePosition) -> void {
        auto event = std::make_unique<Event>("Key" + pressedKey, EventType::KeyPressed);
        m_eventManager.addEvent(std::move(event));
    }

    auto InputManager::passiveMotionHandler(int xMousePosition, int yMousePosition) -> void {
        auto event = std::make_unique<Event>("Mouse " + xMousePosition + " " + yMousePosition, EventType::MouseMoved);
    }

    auto InputManager::motionHandler(int xMousePosition, int yMousePosition) -> void {}

    auto InputManager::mouseHandler(int button, int buttonState, int xMousePosition, int yMousePosition) -> void {
        switch (button) {
            case GLUT_LEFT_BUTTON:
                if (buttonState == GLUT_DOWN) {
                };
                break;
            case GLUT_MIDDLE_BUTTON:
                if (buttonState == GLUT_DOWN) {
                };
                break;
            case GLUT_RIGHT_BUTTON:
                if (buttonState == GLUT_DOWN) {
                };
                break;
            default:
                break;
        }
    }

    auto InputManager::getButtonDown(unsigned char button) -> bool {
        return m_eventManager.hasEvent("Key" + button);
    }

}  // namespace AnimeDefendersEngine
