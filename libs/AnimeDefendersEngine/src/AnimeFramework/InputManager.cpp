#include "InputManager.hpp"

using namespace AnimeDefendersEngine;
using namespace AnimeDefendersEngine::InputManager;

auto keyboardHandler(unsigned char key, int x, int y) -> void
{
    if (key == 'w')
    {
        Event event{"MoveForward", EventType::KeyPressed};
        EventManager::addEvent(event);
    }
        if (key == 's')
    {
        Event event{"MoveBackwards", EventType::KeyPressed};
        EventManager::addEvent(event);
    }
}

    auto initInputManager(Graphics::Window& window) -> void{
    window.setWindowKeyboardListener(keyboardHandler);
}
