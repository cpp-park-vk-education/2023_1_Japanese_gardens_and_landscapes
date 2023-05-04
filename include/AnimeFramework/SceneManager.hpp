#pragma once
#include "Scene.hpp"

namespace AnimeDefendersEngine {
    class ISceneManager {
     public:
        virtual auto getActiveScene() -> Scene& = 0;
        virtual void loadSceme(int sceneId) = 0;
    };

    class SceneManager : public ISceneManager {
     public:
        auto getActiveScene() -> Scene& override;
        void loadSceme(int sceneId) override;
        void addScene(Scene);

     private:
        std::vector<Scene> m_scenes;
    };

}  // namespace AnimeDefendersEngine