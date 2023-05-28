#pragma once

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

     public:
        friend class SceneLoader;

     private:
        std::size_t m_activeSceneId{};
        std::unordered_map<int, std::unique_ptr<Scene>> m_scenes;
    };

}  // namespace AnimeDefendersEngine
