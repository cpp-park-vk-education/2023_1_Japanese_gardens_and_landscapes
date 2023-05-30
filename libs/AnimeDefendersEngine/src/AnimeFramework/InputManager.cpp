#include "InputManager.hpp"

namespace AnimeDefendersEngine {

    InputManager::InputManager(EventManager& eventManager, Graphics::Window& window) : m_eventManager(eventManager) {
        window.setWindowKeyboardListener(keyboardHandler);
        window.setWindowMouseListener(mouseHandler);
        window.setWindowMotionListener(motionHandler);
    }

    auto InputManager::keyboardHandler(unsigned char pressedKey, int xMousePosition, int yMousePosition) -> void {
        auto event = std::make_unique<Event>("Key" + std::to_string(pressedKey), EventType::KeyPressed);
        m_eventManager.addEvent(std::move(event));
    }

    auto InputManager::passiveMotionHandler(int xMousePosition, int yMousePosition) -> void {
        auto event = std::make_unique<Event>("MoveMouse " + std::to_string(xMousePosition) + " " + std::to_string(yMousePosition),
                                             EventType::MouseMoved);
        m_eventManager.addEvent(std::move(event));
    }

    auto InputManager::motionHandler(int xMousePosition, int yMousePosition) -> void {
        auto event = std::make_unique<Event>("ActiveMoveMouse " + std::to_string(xMousePosition) + " " + std::to_string(yMousePosition),
                                             EventType::MouseMoved);
        m_eventManager.addEvent(std::move(event));
    }

    auto InputManager::mouseHandler(int button, int buttonState, int xMousePosition, int yMousePosition) -> void {
        auto event{nullptr};
        switch (button) {
            case GLUT_LEFT_BUTTON:
                if (buttonState == GLUT_DOWN) {
                    event = std::make_unique<Event>(
                        "MouseLeft" + std::to_string(button) + " " + std::to_string(xMousePosition) + " " + std::to_string(yMousePosition),
                        EventType::MouseButtonPressed);
                };
                break;
            case GLUT_MIDDLE_BUTTON:
                if (buttonState == GLUT_DOWN) {
                    event = std::make_unique<Event>("MouseMiddle" + std::to_string(button) + " " + std::to_string(xMousePosition) + " " +
                                                        std::to_string(yMousePosition),
                                                    EventType::MouseButtonPressed);
                };
                break;
            case GLUT_RIGHT_BUTTON:
                if (buttonState == GLUT_DOWN) {
                    event = std::make_unique<Event>(
                        "MouseRight" + std::to_string(button) + " " + std::to_string(xMousePosition) + " " + std::to_string(yMousePosition),
                        EventType::MouseButtonPressed);
                };
                break;
        }
        m_eventManager.addEvent(std::move(event));
    }

    auto InputManager::getButtonDown(unsigned char button) -> bool {
        return m_eventManager.hasEvent("Key" + std::to_string(button));
    }

    auto InputManager::getMouseButtonDown(unsigned char button) -> bool {
        return m_eventManager.hasEvent("Mouse" + std::to_string(button));
    }

    auto InputManager::getPassiveMouseMove() -> bool {
        return m_eventManager.hasEvent("MoveMouse");
    }

    auto InputManager::getActiveMouseMove() -> bool {
        return m_eventManager.hasEvent("ActiveMoveMouse");
    }

}  // namespace AnimeDefendersEngine
