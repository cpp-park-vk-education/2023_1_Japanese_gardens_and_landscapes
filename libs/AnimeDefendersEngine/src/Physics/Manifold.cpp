#include "Manifold.hpp"

using namespace AnimeDefendersEngine::Physics;

Manifold::Manifold(Body* bodyA, Body* bodyB) : bodyA(bodyA), bodyB(bodyB), normal(), penetration(0){};
