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

constexpr float defaultFixedUpdateFrequency = 60.f;
constexpr float defaultMinUpdateFrequency = 25.f;

namespace AnimeDefendersEngine {

    class GameLoop {
     public:
        GameLoop(std::unique_ptr<ISystemManager>&& systemManager, std::unique_ptr<Graphics::Renderer>&& renderer,
                 SceneManager& sceneManager, float fixedDeltaTime = 1.f / defaultMinUpdateFrequency,
                 float maxDeltaTime = 1.f / defaultFixedUpdateFrequency);
        auto run() -> void;

        auto setSystemManager(std::unique_ptr<ISystemManager>&& systemManager) -> void;
        auto setRenderer(std::unique_ptr<Graphics::Renderer>&& renderer) -> void;

     private:
        bool m_isRunning{true};
        float m_maxDeltaTime;
        float m_fixedDeltaTime;

        std::unique_ptr<ISystemManager> m_systemManager;
        std::unique_ptr<Graphics::Renderer> m_renderer;

        SceneManager& m_sceneManager;
    };

}  // namespace AnimeDefendersEngine
