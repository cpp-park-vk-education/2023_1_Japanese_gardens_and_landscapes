#pragma once

#include "BodyDefinition.hpp"
#include "Vector2.hpp"

namespace AnimeDefendersEngine::Physics {

    class Body {
     public:
        explicit Body(BodyDefinition&& bodyDefinition);

        virtual auto applyForce(Math::Vector2f vec) -> void;
        virtual auto applyImpulse(Math::Vector2f vec) -> void;

        virtual auto integrateForce(float deltaTime) -> void;
        virtual auto integrateVelocity(float deltaTime) -> void;

        virtual auto getPosition() const -> Math::Vector2f;
        virtual auto getVelocity() const -> Math::Vector2f;
        virtual auto getShape() const -> Shape*;
        virtual auto getShapeType() const -> ShapeType;
        virtual auto isTrigger() const -> bool;

        virtual auto setPosition(const Math::Vector2f& newPosition) -> void;
        virtual auto setVelocity(const Math::Vector2f& newVelocity) -> void;
        virtual auto setType(BodyType type) -> void;

     private:
        size_t m_id;
        std::unique_ptr<Shape> m_shape;
        BodyType m_bodyType;
        Transform m_transform;
        Math::Vector2f m_velocity;
        size_t m_layers;
        Math::Vector2f m_force;
        bool m_isTrigger;
    };

}  // namespace AnimeDefendersEngine::Physics
