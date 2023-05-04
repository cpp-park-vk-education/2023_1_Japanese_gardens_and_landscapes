#pragma once

#include "ComponentManager.hpp"

namespace AnimeDefendersEngine {
    class ISystem {
     public:
        virtual void updateSystem(IComponentManager&) = 0;
    };
}  // namespace AnimeDefendersEngine