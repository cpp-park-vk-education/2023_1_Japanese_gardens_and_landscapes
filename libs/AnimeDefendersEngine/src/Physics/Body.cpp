#include "Body.hpp"

using namespace AnimeDefendersEngine::Physics;

auto Body::setType(BodyType bodyType) -> void {
    m_bodyType = bodyType;
}

auto Body::applyForce(Math::Vector2f) -> void {}

auto Body::applyImpulse(Math::Vector2f) -> void {}

auto Body::integrateForce(float deltaTime) -> void {
    m_velocity = m_velocity + deltaTime * m_force;
}

auto Body::integrateVelocity(float deltaTime) -> void {
    m_transform.position = m_transform.position + deltaTime * m_velocity;
}

auto Body::getPosition() const -> Math::Vector2f {
    return m_transform.position;
}

auto Body::isTrigger() const -> bool {
    return m_isTrigger;
}

auto Body::setPosition(const Math::Vector2f& newPosition) -> void {
    m_transform.position = newPosition;
}

auto Body::getVelocity() const -> Math::Vector2f {
    return m_velocity;
}

auto Body::setVelocity(const Math::Vector2f& newVelocity) -> void {
    m_velocity = newVelocity;
}

auto Body::getType() const -> BodyType {
    return m_bodyType;
}

auto Body::getShape() const -> Shape* {
    return m_shape.get();
}

auto Body::getShapeType() const -> ShapeType {
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
