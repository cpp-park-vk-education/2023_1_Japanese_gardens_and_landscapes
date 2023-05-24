#pragma once

#include <memory>

namespace AnimeDefendersEngine {

    class ISystemManager;
    class IEventManager;
    class InputManager;
    class SceneManager;
    class ComponentManager;

    namespace Graphics {

        class Renderer;

    }

}  // namespace AnimeDefendersEngine

namespace AnimeDefendersEngine {

    class GameLoop {
     public:
        GameLoop(std::unique_ptr<ISystemManager> systemManager, std::unique_ptr<Graphics::Renderer> renderer, SceneManager& sceneManager);
        GameLoop(std::unique_ptr<ISystemManager> systemManager, std::unique_ptr<Graphics::Renderer> renderer, SceneManager& sceneManager,
                 float fixedDeltaTime, float maxDeltaTime);

        auto run() -> void;

        auto setSystemManager(std::unique_ptr<ISystemManager> systemManager) noexcept -> void;
        auto setRenderer(std::unique_ptr<Graphics::Renderer> renderer) noexcept -> void;

     private:
        bool m_isRunning{true};
        float m_maxDeltaTime;
        float m_fixedDeltaTime;

        std::unique_ptr<ISystemManager> m_systemManager;
        std::unique_ptr<Graphics::Renderer> m_renderer;

        SceneManager& m_sceneManager;
    };

}  // namespace AnimeDefendersEngine
