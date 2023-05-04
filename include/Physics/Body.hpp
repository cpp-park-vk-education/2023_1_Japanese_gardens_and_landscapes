#pragma once

#include "BodyDefinition.hpp"
#include "Vector2.hpp"

namespace AnimeDefendersEngine {
    namespace PhysicsEngine {
        class IBody {
         public:
            virtual void applyForce(Math::Vector2<float> vec) = 0;
            virtual void applyImpulse(Math::Vector2<float> vec) = 0;
            virtual Math::Vector2<float> getPosition() = 0;
            virtual ~IBody(){};
        };

        class Body : public IBody {
         private:
            BodyDefinition bodyDefinition;

         public:
            void setType(BodyType type);
        };
    }  // namespace PhysicsEngine
}  // namespace AnimeDefendersEngine