#pragma once

#include "ISystem.hpp"

namespace AnimeDefendersEngine {

    class ISystemManager {
     public:
        virtual void updateSystems(IComponentManager&) = 0;
        virtual void addSystem(std::unique_ptr<ISystem>) = 0;
    };

    class SystemManager : public ISystemManager {
     public:
        void updateSystems(IComponentManager&) override;
        void addSystem(std::unique_ptr<ISystem>) override;

     protected:
        std::vector<ISystem*> m_systems;
    };
}  // namespace AnimeDefendersEngine