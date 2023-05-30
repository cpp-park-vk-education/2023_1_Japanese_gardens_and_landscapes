#include "PhysicsSystem.hpp"
#include "Body.hpp"
#include "CollisionHandler.hpp"
#include "Manifold.hpp"
#include "Vector2.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace AnimeDefendersEngine::Physics {

    using AnimeDefendersEngine::Math::Vector2f;
    TEST(test1, test2) {
        PhysicsSystem system(0.2f);
    }

}  // namespace AnimeDefendersEngine::Physics