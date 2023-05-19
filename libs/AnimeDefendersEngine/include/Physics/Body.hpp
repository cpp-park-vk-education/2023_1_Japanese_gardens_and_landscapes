#pragma once

#include "BodyDefinition.hpp"
#include "Vector2.hpp"

namespace AnimeDefendersEngine::Physics {

    class Body {
     public:
        explicit Body(BodyDefinition&& bodyDefinition);

        virtual auto applyForce(const Math::Vector2f& force) noexcept -> void;
        virtual auto applyImpulse(const Math::Vector2f& velocity) noexcept -> void;

        virtual auto integrateForce(float deltaTime) noexcept -> void;
        virtual auto integrateVelocity(float deltaTime) noexcept -> void;

        virtual auto getPosition() const noexcept -> Math::Vector2f;
        virtual auto getVelocity() const noexcept -> Math::Vector2f;
        virtual auto getShape() const noexcept -> Shape*;
        virtual auto getShapeType() const noexcept -> ShapeType;
        virtual auto isTrigger() const noexcept -> bool;

        virtual auto setPosition(const Math::Vector2f& newPosition) noexcept -> void;
        virtual auto setVelocity(const Math::Vector2f& newVelocity) noexcept -> void;
        virtual auto setType(BodyType type) noexcept -> void;

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
