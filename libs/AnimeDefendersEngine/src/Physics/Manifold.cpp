#include "Manifold.hpp"

using namespace AnimeDefendersEngine::Physics;

Manifold::Manifold(IBody* bodyA, IBody* bodyB) : bodyA(bodyA), bodyB(bodyB), normal(), penetration(0){};
