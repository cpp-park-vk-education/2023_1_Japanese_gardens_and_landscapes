#pragma once

#include "Scene.hpp"

#include <memory>
#include <unordered_map>

namespace AnimeDefendersEngine {

    class Scene;
    class SceneLoader;

}  // namespace AnimeDefendersEngine

namespace AnimeDefendersEngine {

    class SceneManager {
     public:
        [[nodiscard]] auto getActiveScene() -> Scene&;
        auto setActiveScene(std::size_t sceneId) noexcept -> void;

        auto addScene(std::unique_ptr<Scene> scene) -> void;

        [[nodiscard]] auto getScenes() -> std::unordered_map<Scene::IdType, std::unique_ptr<Scene>>&;

     private:
        Scene::IdType m_activeSceneId{};
        std::unordered_map<Scene::IdType, std::unique_ptr<Scene>> m_scenes;
    };

}  // namespace AnimeDefendersEngine
