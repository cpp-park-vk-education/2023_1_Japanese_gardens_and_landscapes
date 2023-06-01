#pragma once

#include "BaseComponent.hpp"
#include "ComponentManager.hpp"
#include "InputManager.hpp"

namespace AnimeDefendersEngine {

    class InputComponent : public BaseComponent<InputComponent> {
     public:
        InputComponent(const std::string& entityId, ComponentManager& compManager, InputManager& inputManager)
            : BaseComponent<InputComponent>(entityId, compManager), m_inputManager(inputManager) {}

        auto getButtonDown(unsigned char button) -> bool { return m_inputManager.getButtonDown(button); }

        auto getMouseButtonDown(unsigned char button) -> bool { return m_inputManager.getButtonDown(button); }

        auto getPassiveMouseMove() -> bool { return m_inputManager.getPassiveMouseMove(); }

        auto getActiveMouseMove() -> bool { return m_inputManager.getActiveMouseMove(); }

     private:
        InputManager& m_inputManager;
    };

}  // namespace AnimeDefendersEngine
