#pragma once

#include "BodyDefinition.hpp"

namespace AnimeDefendersEngine {
    namespace PhysicsEngine {
        class IBody {
         public:
            // virtual void applyForce(Vector2d vec) = 0;
            // virtual void applyImpulse(Vector2d vec) = 0;
            // virtual Vector2d getPosition() = 0;
            virtual ~IBody(){};
        };

        using IBodyUPtr = std::unique_ptr<IBody>;

        class Body : public IBody {
         private:
            BodyDefinition bodyDefinition;

         public:
            void setType(BodyType type);
        };
    }  // namespace PhysicsEngine
}  // namespace AnimeDefendersEngine