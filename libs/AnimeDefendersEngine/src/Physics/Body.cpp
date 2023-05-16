#include "Body.hpp"

using namespace AnimeDefendersEngine::Physics;

auto Body::setType(BodyType) -> void {}

auto Body::applyForce(Math::Vector2<float>) -> void {}

auto Body::applyImpulse(Math::Vector2<float>) -> void {}

auto Body::getPosition() -> Math::Vector2<float> {
    return Math::Vector2<float>{0, 0};
}

auto Body::setPosition(const Math::Vector2<float>& newPos) -> void {}
