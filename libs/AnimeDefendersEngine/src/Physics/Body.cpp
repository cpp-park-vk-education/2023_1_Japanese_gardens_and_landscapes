#include "Body.hpp"

using namespace AnimeDefendersEngine::Physics;

auto Body::setType(BodyType bodyType) noexcept -> void {
    m_bodyType = bodyType;
}

auto Body::applyForce(const Math::Vector2f& force) noexcept -> void {
    m_force = m_force + force;
}

auto Body::applyImpulse(const Math::Vector2f& velocity) noexcept -> void {
    m_velocity = m_velocity + velocity;
}

auto Body::integrateForce(float deltaTime) noexcept -> void {
    m_velocity = m_velocity + deltaTime * m_force;
}

auto Body::integrateVelocity(float deltaTime) noexcept -> void {
    m_transform.position = m_transform.position + deltaTime * m_velocity;
}

auto Body::getPosition() const noexcept -> Math::Vector2f {
    return m_transform.position;
}

auto Body::isTrigger() const noexcept -> bool {
    return m_isTrigger;
}

auto Body::setPosition(const Math::Vector2f& newPosition) noexcept -> void {
    m_transform.position = newPosition;
}

auto Body::getVelocity() const noexcept -> Math::Vector2f {
    return m_velocity;
}

auto Body::setVelocity(const Math::Vector2f& newVelocity) noexcept -> void {
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

auto Body::clearForce() -> void {
    m_force = AnimeDefendersEngine::Math::Vector2f(0, 0);
}

Body::Body(BodyDefinition&& bodyDefinition)
    : m_id(bodyDefinition.id),
      m_shape(std::move(bodyDefinition.shape)),
      m_bodyType(bodyDefinition.bodyType),
      m_transform(bodyDefinition.transform),
      m_velocity(bodyDefinition.velocity),
      m_layers(bodyDefinition.layers),
      m_force(bodyDefinition.force),
      m_isTrigger(bodyDefinition.isTrigger) {}
