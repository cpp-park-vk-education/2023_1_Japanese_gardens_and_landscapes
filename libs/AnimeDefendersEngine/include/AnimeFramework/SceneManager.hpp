#pragma once
#include "Scene.hpp"

namespace AnimeDefendersEngine {

    class ISceneManager {
     public:
        virtual auto getActiveScene() -> Scene* = 0;
        virtual void loadScene(int sceneId) = 0;
    };

    class SceneManager : public ISceneManager {
     public:
        auto getActiveScene() -> Scene* override;
        void loadScene(int sceneId) override;

     private:
        std::vector<Scene> m_scenes;
    };

}  // namespace AnimeDefendersEngine
