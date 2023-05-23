#pragma once

#include "ISystem.hpp"

#include <vector>

namespace AnimeDefendersEngine {

    class ISystemManager {
     public:
        virtual void updateSystems(ComponentManager&) = 0;
    };

    class SystemManager : public ISystemManager {
     public:
        void updateSystems(ComponentManager&) override;

     private:
        std::vector<ISystem*> m_systems;
    };

}  // namespace AnimeDefendersEngine
