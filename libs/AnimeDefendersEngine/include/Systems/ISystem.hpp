#pragma once

#include "ComponentManager.hpp"

namespace AnimeDefendersEngine {

    class ISystem {
     public:
        virtual void updateSystem(ComponentManager&) = 0;
    };

}  // namespace AnimeDefendersEngine
