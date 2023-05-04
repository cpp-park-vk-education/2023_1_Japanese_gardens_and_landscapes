#pragma once

#include <vector>
#include "Body.hpp"
#include "Manifold.hpp"

namespace AnimeDefendersEngine {
    namespace PhysicsEngine {
        class PhysicsWorld {
         public:
            PhysicsWorld(const float fixedDeltaTime);
            void setFixedDeltaTime(const float fixedDeltaTime);
            void update(const float timeStep);
            auto addBody(const BodyDefinition& bodyDefinition) -> IBody*;
            void removeBody(IBody* body);

         private:
            std::vector<IBodyUPtr> bodies;
            std::vector<Manifold> contacts;
            void fixedUpdate();

            float m_fixedDeltaTime;
        };
    }  // namespace PhysicsEngine
}  // namespace AnimeDefendersEngine