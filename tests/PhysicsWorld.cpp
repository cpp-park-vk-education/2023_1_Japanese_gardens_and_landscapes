#include "PhysicsWorld.hpp"
#include "Body.hpp"
#include "CollisionHandler.hpp"
#include "Vector2.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace AnimeDefendersEngine::Physics {

    using AnimeDefendersEngine::Math::Vector2f;

    class PhysicsWorldTest : public testing::Test {
     protected:
        void SetUp() override {}

        void TearDown() override {}

        PhysicsWorld physicsWorld;
        CollisionHandler collisionHandler;
        BodyDefinition bodyDefinition;
    };

    TEST_F(CollisionDetectionTest, TwoCirclesHaveCollision) {
        const auto radius = 1.f;

        bodyDefinition.shape = std::make_unique<Circle>(radius);
        Body bodyA(std::move(bodyDefinition));

        bodyDefinition.shape = std::make_unique<Circle>(radius);
        bodyDefinition.transform.position = Vector2f(radius, 0);
        Body bodyB(std::move(bodyDefinition));

        const auto actual = collisionHandler.hasCollision(&bodyA, &bodyB);
        const auto expected = true;
        EXPECT_EQ(expected, actual);
    }
}  // namespace AnimeDefendersEngine::Physics