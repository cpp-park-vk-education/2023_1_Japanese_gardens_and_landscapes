#pragma once

// static_assert(false, "Need to add propper headers for IEventManager and InputManager");
#include "InputManager.hpp"
#include "Renderer.hpp"
#include "SceneManager.hpp"
#include "SystemManager.hpp"

#include <memory>

namespace AnimeDefendersEngine {

    class GameLoop {
     public:
        GameLoop(std::unique_ptr<ISystemManager>&& systemManager, std::unique_ptr<IEventManager>&& eventManager,
                 std::unique_ptr<InputManager>&& inputManager, std::unique_ptr<Graphics::Renderer>&& renderer, SceneManager* sceneManager,
                 ComponentManager* componentManager, float fixedDeltaTime, float maxDeltaTime);
        auto run() -> void;

        auto setSystemManager(std::unique_ptr<ISystemManager>&& systemManager) -> void;
        auto setEventManager(std::unique_ptr<IEventManager>&& eventManager) -> void;
        auto setInputManager(std::unique_ptr<InputManager>&& inputManager) -> void;
        auto setRenderer(std::unique_ptr<Graphics::Renderer>&& renderer) -> void;

     private:
        bool m_isRunning{true};
        float m_maxDeltaTime{1.0f / 25.0f};
        float m_fixedDeltaTime{1.0f / 60.0f};

        std::unique_ptr<ISystemManager> m_systemManager;
        std::unique_ptr<IEventManager> m_eventManager;
        std::unique_ptr<InputManager> m_inputManager;
        std::unique_ptr<Graphics::Renderer> m_renderer;

        SceneManager* m_sceneManager;
        ComponentManager* m_componentManager;
    };

}  // namespace AnimeDefendersEngine
