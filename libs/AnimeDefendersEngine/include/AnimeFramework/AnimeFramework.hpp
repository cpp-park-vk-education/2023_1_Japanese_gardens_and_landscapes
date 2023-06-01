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
        explicit AnimeFramework();
        auto run() -> void;

     private:
        SceneManager m_sceneManager;
        GameLoop m_gameLoop;
    };
}  // namespace AnimeDefendersEngine
