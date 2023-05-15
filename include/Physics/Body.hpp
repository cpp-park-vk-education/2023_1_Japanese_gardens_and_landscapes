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
         public:
            virtual auto applyForce(Math::Vector2<float> vec) -> void override;
            virtual auto applyImpulse(Math::Vector2<float> vec) -> void override;
            virtual auto getPosition() -> Math::Vector2<float> override;
            auto setType(BodyType type) -> void;

         private:
            BodyDefinition bodyDefinition;
        };

    }  // namespace PhysicsEngine
}  // namespace AnimeDefendersEngine
