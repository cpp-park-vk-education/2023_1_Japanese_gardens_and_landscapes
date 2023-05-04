#pragma once

#include "BodyDefinition.hpp"
#include "Vector2.hpp"

namespace AnimeDefendersEngine {
    namespace PhysicsEngine {
        class IBody {
         public:
            virtual auto applyForce(Math::Vector2<float> vec) -> void = 0;
            virtual auto applyImpulse(Math::Vector2<float> vec) -> void = 0;
            virtual auto getPosition() -> Math::Vector2<float> = 0;
            virtual ~IBody(){};
        };

        class Body : public IBody {
         private:
            BodyDefinition bodyDefinition;

         public:
            auto setType(BodyType type) -> void;
        };
    }  // namespace PhysicsEngine
}  // namespace AnimeDefendersEngine