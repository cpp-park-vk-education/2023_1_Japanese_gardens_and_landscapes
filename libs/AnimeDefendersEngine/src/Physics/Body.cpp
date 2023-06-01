#include "Body.hpp"

namespace AnimeDefendersEngine::Physics {

    using AnimeDefendersEngine::Math::Vector2f;

    auto Body::setType(BodyType bodyType) noexcept -> void {
        m_bodyType = bodyType;
        if (bodyType == BodyType::staticBody) {
            m_inverseMass = 0.f;
        }
    }

    auto Body::applyForce(const Vector2f& force) noexcept -> void {
        m_force = m_force + force;
    }

    auto Body::applyImpulse(const Vector2f& velocity) noexcept -> void {
        m_velocity = m_velocity + velocity;
    }

    auto Body::integrateForce(float deltaTime) noexcept -> void {
        m_velocity = m_velocity + (deltaTime * m_force);
    }

    auto Body::integrateVelocity(float deltaTime) noexcept -> void {
        m_transform.position = m_transform.position + (deltaTime * m_velocity);
    }

    auto Body::getPosition() const noexcept -> Vector2f {
        return m_transform.position;
    }

    auto Body::isTrigger() const noexcept -> bool {
        return m_isTrigger;
    }

    auto Body::setPosition(const Vector2f& newPosition) noexcept -> void {
        m_transform.position = newPosition;
    }

    auto Body::getVelocity() const noexcept -> Vector2f {
        return m_velocity;
    }

    auto Body::getInverseMass() const noexcept -> float {
        return m_inverseMass;
    }

    auto Body::setVelocity(const Vector2f& newVelocity) noexcept -> void {
        m_velocity = newVelocity;
    }

    auto Body::getType() const noexcept -> BodyType {
        return m_bodyType;
    }

    auto Body::getShape() const noexcept -> Shape* {
        return m_shape.get();
    }

    auto Body::getShapeType() const noexcept -> ShapeType {
        return m_shape->getType();
    }

    auto Body::getID() const noexcept -> const std::string& {
        return m_id;
    }

    auto Body::clearForce() noexcept -> void {
        m_force = Vector2f{};
    }

    auto Body::clearVelocity() noexcept -> void {
        m_velocity = Vector2f{};
    }

    Body::Body(BodyDefinition&& bodyDefinition)
        : m_id(bodyDefinition.id),
          m_shape(std::move(bodyDefinition.shape)),
          m_bodyType(bodyDefinition.bodyType),
          m_transform(bodyDefinition.transform),
          m_velocity(bodyDefinition.velocity),
          m_layers(bodyDefinition.layers),
          m_force(bodyDefinition.force),
          m_isTrigger(bodyDefinition.isTrigger) {
        if (bodyDefinition.bodyType == BodyType::staticBody) {
            m_inverseMass = 0;
        } else {
            m_inverseMass = 1.f / bodyDefinition.mass;
        }
    }

}  // namespace AnimeDefendersEngine::Physics
