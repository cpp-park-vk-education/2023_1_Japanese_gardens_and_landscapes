#pragma once

#include <memory>

namespace AnimeDefendersEngine {

    class ISystemManager;
    class EventManager;
    class SceneManager;
    class ComponentManager;

    namespace Graphics {

        class Renderer;

    }  // namespace Graphics

}  // namespace AnimeDefendersEngine

namespace AnimeDefendersEngine {

    class GameLoop {
     public:
        GameLoop(std::unique_ptr<ISystemManager> systemManager, std::unique_ptr<Graphics::Renderer> renderer,
                 std::unique_ptr<EventManager> eventManager, SceneManager& sceneManager);
        GameLoop(std::unique_ptr<ISystemManager> systemManager, std::unique_ptr<Graphics::Renderer> renderer,
                 std::unique_ptr<EventManager> eventManager, SceneManager& sceneManager, float fixedDeltaTime, float maxDeltaTime);

        auto run() -> void;

     private:
        bool m_isRunning{true};
        float m_maxDeltaTime{};
        float m_fixedDeltaTime{};

        std::unique_ptr<ISystemManager> m_systemManager;
        std::unique_ptr<Graphics::Renderer> m_renderer;
        std::unique_ptr<EventManager> m_eventManager;

        SceneManager& m_sceneManager;
    };

}  // namespace AnimeDefendersEngine
