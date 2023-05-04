#pragma once

#include <vector>
#include "Body.hpp"
#include "Manifold.hpp"

namespace AnimeDefendersEngine {
    namespace PhysicsEngine {
        class PhysicsWorld {
         public:
            PhysicsWorld(const float fixedDeltaTime);
            auto setFixedDeltaTime(const float fixedDeltaTime) -> void;
            auto update(const float timeStep) -> void;
            auto addBody(const BodyDefinition& bodyDefinition) -> IBody*;
            auto removeBody(IBody* body) -> void;

         private:
            void fixedUpdate();
            std::vector<IBodyUPtr> m_bodies;
            std::vector<Manifold> m_contacts;

            float m_fixedDeltaTime;
        };
    }  // namespace PhysicsEngine
}  // namespace AnimeDefendersEngine