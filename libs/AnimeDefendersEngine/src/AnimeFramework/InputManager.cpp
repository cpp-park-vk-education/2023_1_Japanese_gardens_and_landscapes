#include "InputManager.hpp"
#include <memory>
auto AnimeDefendersEngine::InputManager::keyboardHandler(unsigned char key, int x, int y) -> void {
    if (key == 'w') {
        auto event = std::make_unique<Event>("MoveForward", EventType::KeyPressed);
        EventManager::addEvent(std::move(event));
    }
    if (key == 's') {
        auto event = std::make_unique<Event>("MoveBackwards", EventType::KeyPressed);
        EventManager::addEvent(std::move(event));
    }
}

auto AnimeDefendersEngine::InputManager::initInputManager(Graphics::Window& window) -> void {
    window.setWindowKeyboardListener(keyboardHandler);
}
