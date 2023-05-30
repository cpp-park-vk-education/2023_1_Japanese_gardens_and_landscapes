#pragma once

#include "ISystem.hpp"
#include "SceneManager.hpp"

namespace AnimeDefendersEngine {

    class OnFixedUpdateSystem : public ISystem {
     public:
        auto updateSystem(SceneManager& sceneManager) -> void override;
    };

}  // namespace AnimeDefendersEngine
