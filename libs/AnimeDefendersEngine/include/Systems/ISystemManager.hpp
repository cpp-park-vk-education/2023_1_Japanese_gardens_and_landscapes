#pragma once

namespace AnimeDefendersEngine {

    class SceneManager;

}  // namespace AnimeDefendersEngine

namespace AnimeDefendersEngine {

    class ISystemManager {
     public:
        virtual void updateSystems(SceneManager& sceneManager, float fixedDeltaTime) = 0;
        virtual ~ISystemManager() = default;
    };

}  // namespace AnimeDefendersEngine