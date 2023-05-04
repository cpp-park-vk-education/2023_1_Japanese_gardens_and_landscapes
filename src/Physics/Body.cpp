#include "Body.hpp"

using namespace AnimeDefendersEngine::PhysicsEngine;

auto Body::setType(BodyType type) -> void{};
auto Body::applyForce(Math::Vector2<float> vec) -> void{};
auto Body::applyImpulse(Math::Vector2<float> vec) -> void{};
auto Body::getPosition() -> Math::Vector2<float>{};