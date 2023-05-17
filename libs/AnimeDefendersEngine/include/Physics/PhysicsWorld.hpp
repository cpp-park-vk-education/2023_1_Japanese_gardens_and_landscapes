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
            auto addBody(const BodyDefinition& bodyDefinition) -> Body*;
            auto removeBody(Body* body) -> void;

         private:
            auto fixedUpdate() -> void;

            std::vector<std::unique_ptr<Body>> m_bodies;
            std::vector<Manifold> m_contacts;
            float m_fixedDeltaTime{};
        };

    }  // namespace Physics
}  // namespace AnimeDefendersEngine
