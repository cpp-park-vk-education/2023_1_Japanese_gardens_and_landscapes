#pragma once

#include "ComponentManager.hpp"
#include "Entity.hpp"
#include "EventManager.hpp"
#include "GameLoop.hpp"
#include "IEntityCreator.hpp"
#include "Renderer.hpp"
#include "SceneLoader.hpp"
#include "SceneManager.hpp"
#include "SystemManager.hpp"
#include "Window.hpp"

#include <fstream>
#include <memory>

namespace AnimeDefendersEngine {

    /**
     * @brief Dummy required by AnimeFramework
     *  Must be defined by game developer
     */
    class BaseCreator : public IEntityCreator {
     public:
        auto create(const std::vector<std::string>& arguments, Scene& scene) -> std::shared_ptr<Entity> override {
            return std::make_shared<Entity>("Hi", scene);
        };
    };

    /**
     * @brief Should be redefined by game developer
     */
    class AnimeFramework {
     public:
        explicit AnimeFramework()
            : m_sceneManager{},
              m_gameLoop{std::make_unique<SystemManager>(),
                         std::make_unique<Graphics::Renderer>(std::make_unique<Graphics::Window>(1280, 1280, "Gaaaaaay")),
                         std::make_unique<EventManager>(), m_sceneManager} {}

        auto run() -> void {
            auto readStream = std::make_unique<std::ifstream>("SamplePath");
            auto entityCreator = std::make_unique<BaseCreator>();

            SceneLoader loadScenes{std::move(readStream), std::move(entityCreator), m_sceneManager};
            m_sceneManager.setActiveScene(2);

            m_gameLoop.run();
        }

     private:
        SceneManager m_sceneManager;
        GameLoop m_gameLoop;
    };
}  // namespace AnimeDefendersEngine
