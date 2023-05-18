#pragma once

#include "BodyDefinition.hpp"
#include "Vector2.hpp"

namespace AnimeDefendersEngine::Physics {

    class Body {
     public:
        explicit Body(BodyDefinition&& bodyDefinition);

        virtual auto applyForce(Math::Vector2<float> vec) -> void;
        virtual auto applyImpulse(Math::Vector2<float> vec) -> void;

        virtual auto getPosition() -> Math::Vector2<float>;
        virtual auto getVelocity() -> Math::Vector2<float>;
        virtual auto getShape() -> Shape*;
        virtual auto getShapeType() const -> ShapeType;
        virtual auto isTrigger() -> bool;

        virtual auto setPosition(const Math::Vector2<float>& newPosition) -> void;
        virtual auto setVelocity(const Math::Vector2<float>& newVelocity) -> void;
        virtual auto setType(BodyType type) -> void;

     private:
        size_t m_id;
        std::unique_ptr<Shape> m_shape;
        BodyType m_bodyType;
        Transform m_transform;
        Math::Vector2<float> m_velocity;
        size_t m_layers;
        Math::Vector2<float> m_force;
        bool m_isTrigger;
    };

}  // namespace AnimeDefendersEngine::Physics
