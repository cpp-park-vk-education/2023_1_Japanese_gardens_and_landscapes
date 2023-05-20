#pragma once

#include <memory>
#include <unordered_map>

namespace AnimeDefendersEngine {
    class Scene;
}

namespace AnimeDefendersEngine {

    class ISceneManager {
     public:
        [[nodiscard]] virtual auto getActiveScene() -> Scene& = 0;
        virtual auto setActiveScene(int sceneId) -> void = 0;
    };

    class SceneManager : public ISceneManager {
     public:
        [[nodiscard]] auto getActiveScene() -> Scene& override;
        auto setActiveScene(int sceneId) noexcept -> void override;

        auto addScene(std::unique_ptr<Scene>&& scene) -> void;

     private:
        int m_activeSceneId{};
        std::unordered_map<int, std::unique_ptr<Scene>> m_scenes;
    };

}  // namespace AnimeDefendersEngine
