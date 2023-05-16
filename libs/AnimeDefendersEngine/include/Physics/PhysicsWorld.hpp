#pragma once

#include <vector>
#include "Body.hpp"
#include "Manifold.hpp"

namespace AnimeDefendersEngine {
    namespace Physics {

        class PhysicsWorld {
         public:
            PhysicsWorld(const float fixedDeltaTime);
            auto setFixedDeltaTime(const float fixedDeltaTime) -> void;
            auto update(const float timeStep) -> void;
            auto addBody(const BodyDefinition& bodyDefinition) -> IBody*;
            auto removeBody(IBody* body) -> void;

         private:
            auto fixedUpdate() -> void;

            std::vector<std::unique_ptr<IBody>> m_bodies;
            std::vector<Manifold> m_contacts;
            float m_fixedDeltaTime;
        };

    }  // namespace Physics
}  // namespace AnimeDefendersEngine
