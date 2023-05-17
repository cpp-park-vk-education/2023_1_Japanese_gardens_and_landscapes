#include "Body.hpp"

using namespace AnimeDefendersEngine::Physics;

auto Body::setType(BodyType) -> void {}

auto Body::applyForce(Math::Vector2<float>) -> void {}

auto Body::applyImpulse(Math::Vector2<float>) -> void {}

auto Body::getPosition() -> Math::Vector2<float> {
    return Math::Vector2<float>{0, 0};
}

auto Body::setPosition(const Math::Vector2<float>& newPosition) -> void {
    Math::Vector2<float> pos = newPosition;
}

auto Body::getVelocity() -> Math::Vector2<float> {
    return Math::Vector2<float>{0, 0};
}

auto Body::setVelocity(const Math::Vector2<float>& newVelocity) -> void {
    Math::Vector2<float> vel = newVelocity;
}

Body::Body(BodyDefinition&& bodyDefinition)
    : m_id(bodyDefinition.id),
      m_shapeUptr(std::move(bodyDefinition.shapeUPtr)),
      m_bodyType(bodyDefinition.bodyType),
      m_transform(bodyDefinition.transform),
      m_velocity(bodyDefinition.velocity),
      m_layers(bodyDefinition.layers),
      m_force(bodyDefinition.force),
      m_isTrigger(bodyDefinition.isTrigger){};
