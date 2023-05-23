#include "InputManager.hpp"
#include "Vector2.hpp"


auto AnimeDefendersEngine::InputManager::keyboardHandler(unsigned char key, int x, int y) -> void {
        auto event = std::make_unique<Event>("Key" + key, EventType::KeyPressed);
        EventManager::addEvent(std::move(event));
    }

auto AnimeDefendersEngine::InputManager::motionHandler(int x, int y) -> void {
}

auto AnimeDefendersEngine::InputManager::initInputManager(Graphics::Window& window) -> void {
    window.setWindowKeyboardListener(keyboardHandler);
    window.setWindowMouseListener(mouseHandler);
    window.setWindowMotionListener(motionHandler);
}

auto getButtonDown(const unsigned char button) -> bool
{
    return AnimeDefendersEngine::EventManager::hasEvent("Key" + button);
}

