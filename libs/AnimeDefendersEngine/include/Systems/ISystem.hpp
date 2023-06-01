#pragma once

#include "SceneManager.hpp"

namespace AnimeDefendersEngine {

    class ISystem {
     public:
        virtual void updateSystem(SceneManager& sceneManager) = 0;
    };

}  // namespace AnimeDefendersEngine
