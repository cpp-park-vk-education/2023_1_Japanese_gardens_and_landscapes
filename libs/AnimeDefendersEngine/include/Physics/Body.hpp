#pragma once

#include "BodyDefinition.hpp"
#include "Vector2.hpp"

namespace AnimeDefendersEngine {
    namespace Physics {

        class IBody {
         public:
            virtual auto applyForce(Math::Vector2<float> vec) -> void = 0;
            virtual auto applyImpulse(Math::Vector2<float> vec) -> void = 0;
            virtual auto getPosition() -> Math::Vector2<float> = 0;
            virtual auto setPosition(const Math::Vector2<float>& newPosition) -> void = 0;
            virtual ~IBody(){};
        };

        class Body : public IBody {
         public:
            virtual auto applyForce(Math::Vector2<float> vec) -> void override;
            virtual auto applyImpulse(Math::Vector2<float> vec) -> void override;
            virtual auto getPosition() -> Math::Vector2<float> override;
            virtual auto setPosition(const Math::Vector2<float>& newPosition) -> void override;
            auto setType(BodyType type) -> void;

         private:
            BodyDefinition bodyDefinition;
        };

    }  // namespace Physics
}  // namespace AnimeDefendersEngine
