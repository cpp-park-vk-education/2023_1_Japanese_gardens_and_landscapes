#pragma once

namespace AnimeDefendersEngine {

    class SceneManager;

}  // namespace AnimeDefendersEngine

namespace AnimeDefendersEngine {

    class ISystemManager {
     public:
        virtual auto updateSystems(SceneManager& sceneManager, float fixedDeltaTime) -> void = 0;
        virtual ~ISystemManager() = default;
    };

}  // namespace AnimeDefendersEngine