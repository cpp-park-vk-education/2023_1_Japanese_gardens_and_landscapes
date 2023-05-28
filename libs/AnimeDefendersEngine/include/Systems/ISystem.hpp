#pragma once

#include "SceneManager.hpp"

namespace AnimeDefendersEngine {

    class ISystem {
     public:
        virtual void updateSystem(SceneManager&) = 0;
    };

}  // namespace AnimeDefendersEngine
