#pragma once

#include "BodyDefinition.hpp"
#include "Vector2.hpp"

#include <string>

namespace AnimeDefendersEngine::Physics {

    class Body {
     public:
        explicit Body(BodyDefinition&& bodyDefinition);

        virtual auto applyForce(const Math::Vector2f& force) noexcept -> void;
        virtual auto applyImpulse(const Math::Vector2f& velocity) noexcept -> void;

        virtual auto integrateForce(float deltaTime) noexcept -> void;
        virtual auto integrateVelocity(float deltaTime) noexcept -> void;

        [[nodiscard]] virtual auto getPosition() const noexcept -> Math::Vector2f;
        [[nodiscard]] virtual auto getVelocity() const noexcept -> Math::Vector2f;
        [[nodiscard]] virtual auto getType() const noexcept -> BodyType;
        [[nodiscard]] virtual auto getInverseMass() const noexcept -> float;
        [[nodiscard]] virtual auto getShape() const noexcept -> Shape*;
        [[nodiscard]] virtual auto getShapeType() const noexcept -> ShapeType;
        [[nodiscard]] virtual auto getID() const noexcept -> std::string;
        [[nodiscard]] virtual auto isTrigger() const noexcept -> bool;

        virtual auto setPosition(const Math::Vector2f& newPosition) noexcept -> void;
        virtual auto setVelocity(const Math::Vector2f& newVelocity) noexcept -> void;
        virtual auto setType(BodyType type) noexcept -> void;

        virtual auto clearForce() noexcept -> void;
        virtual auto clearVelocity() noexcept -> void;

     private:
        std::string m_id;
        std::unique_ptr<Shape> m_shape;
        BodyType m_bodyType;
        Transform m_transform;
        Math::Vector2f m_velocity;
        float m_inverseMass;
        std::size_t m_layers;
        Math::Vector2f m_force;
        bool m_isTrigger;
    };

}  // namespace AnimeDefendersEngine::Physics
