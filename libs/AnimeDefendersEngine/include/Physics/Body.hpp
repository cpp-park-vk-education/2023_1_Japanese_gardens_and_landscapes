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
            virtual auto getVelocity() -> Math::Vector2<float> = 0;
            virtual auto setPosition(const Math::Vector2<float>& newPosition) -> void = 0;
            virtual auto setVelocity(const Math::Vector2<float>& newVelocity) -> void = 0;
            virtual ~IBody(){};
        };

        class Body : public IBody {
         public:
            Body(BodyDefinition&& bodyDefinition);
            virtual auto applyForce(Math::Vector2<float> vec) -> void override;
            virtual auto applyImpulse(Math::Vector2<float> vec) -> void override;
            virtual auto getPosition() -> Math::Vector2<float> override;
            virtual auto getVelocity() -> Math::Vector2<float> override;
            virtual auto setPosition(const Math::Vector2<float>& newPosition) -> void override;
            virtual auto setVelocity(const Math::Vector2<float>& newVelocity) -> void override;
            auto setType(BodyType type) -> void;

         private:
            size_t m_id;
            std::unique_ptr<Shape> m_shapeUptr;
            BodyType m_bodyType;
            Transform m_transform;
            Math::Vector2<float> m_velocity;
            size_t m_layers;
            Math::Vector2<float> m_force;
            bool m_isTrigger;
        };

    }  // namespace Physics
}  // namespace AnimeDefendersEngine
