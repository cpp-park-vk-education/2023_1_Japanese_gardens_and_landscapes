#pragma once

#include <memory>
#include <unordered_map>

namespace AnimeDefendersEngine {
    class Scene;
}

namespace AnimeDefendersEngine {

    class ISceneManager {
     public:
        virtual auto getActiveScene() -> Scene& = 0;
        virtual auto setActiveScene(int sceneId) -> void = 0;
    };

    class SceneManager : public ISceneManager {
     public:
        auto getActiveScene() -> Scene& override {
            auto scenePointer = m_scenes.at(m_activeSceneId).get();
            return *scenePointer;
        };
        auto setActiveScene(int sceneId) -> void override { m_activeSceneId = sceneId; };

        auto addScene(std::unique_ptr<Scene>&& scene) -> void override { m_scenes[scene->getSceneId()] = std::move(scene); };

     private:
        int m_activeSceneId{};
        std::unordered_map<int, std::unique_ptr<Scene>> m_scenes;
    };

}  // namespace AnimeDefendersEngine
