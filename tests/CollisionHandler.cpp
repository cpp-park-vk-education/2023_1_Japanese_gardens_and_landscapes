#include "CollisionHandler.hpp"
#include "Body.hpp"
#include "Vector2.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace AnimeDefendersEngine::Physics {

    using AnimeDefendersEngine::Math::Vector2f;

    class CollisionDetectionTest : public testing::Test {
     protected:
        void SetUp() override {}

        void TearDown() override {}

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

    TEST_F(CollisionDetectionTest, TwoCirclesDontHaveCollision) {
        const auto radius = 1.f;

        bodyDefinition.shape = std::make_unique<Circle>(radius);
        Body bodyA(std::move(bodyDefinition));

        bodyDefinition.shape = std::make_unique<Circle>(radius);
        bodyDefinition.transform.position = Vector2f(2.1f * radius, 0);
        Body bodyB(std::move(bodyDefinition));

        const auto actual = collisionHandler.hasCollision(&bodyA, &bodyB);
        const auto expected = false;
        EXPECT_EQ(expected, actual);
    }

    TEST_F(CollisionDetectionTest, TwoRectanglesDontHaveCollision) {
        const Vector2f size(1, 1);

        bodyDefinition.shape = std::make_unique<Rectangle>(size);
        Body bodyA(std::move(bodyDefinition));

        bodyDefinition.shape = std::make_unique<Rectangle>(size);
        bodyDefinition.transform.position = Vector2f(2, 0);
        Body bodyB(std::move(bodyDefinition));

        const auto actual = collisionHandler.hasCollision(&bodyA, &bodyB);
        const auto expected = false;
        EXPECT_EQ(expected, actual);
    }

    TEST_F(CollisionDetectionTest, TwoRectanglesHaveHorizontalCollision) {
        const Vector2f size(2, 2);

        bodyDefinition.shape = std::make_unique<Rectangle>(size);
        Body bodyA(std::move(bodyDefinition));

        bodyDefinition.shape = std::make_unique<Rectangle>(size);
        bodyDefinition.transform.position = Vector2f(1, 0);
        Body bodyB(std::move(bodyDefinition));

        const auto actual = collisionHandler.hasCollision(&bodyA, &bodyB);
        const auto expected = true;
        EXPECT_EQ(expected, actual);
    }

    TEST_F(CollisionDetectionTest, TwoRectanglesHaveDiagonalCollision) {
        const Vector2f size(2, 2);

        bodyDefinition.shape = std::make_unique<Rectangle>(size);
        Body bodyA(std::move(bodyDefinition));

        bodyDefinition.shape = std::make_unique<Rectangle>(size);
        bodyDefinition.transform.position = Vector2f(1.5f, 1.5f);
        Body bodyB(std::move(bodyDefinition));

        const auto actual = collisionHandler.hasCollision(&bodyA, &bodyB);
        const auto expected = true;
        EXPECT_EQ(expected, actual);
    }

    TEST_F(CollisionDetectionTest, TwoRectanglesDontHaveCollisionBecauseTheyHaveTheSameCenter) {
        const Vector2f position(10, 10);

        bodyDefinition.transform.position = position;

        bodyDefinition.shape = std::make_unique<Rectangle>(Vector2f(100, 2));
        Body bodyA(std::move(bodyDefinition));

        bodyDefinition.shape = std::make_unique<Rectangle>(Vector2f(2, 100));
        Body bodyB(std::move(bodyDefinition));

        const auto actual = collisionHandler.hasCollision(&bodyA, &bodyB);
        const auto expected = true;
        EXPECT_EQ(expected, actual);
    }

    TEST_F(CollisionDetectionTest, CircleAndRectangleDontHaveCollision) {
        const Vector2f size(1, 1);
        const auto radius = 4.f;

        bodyDefinition.shape = std::make_unique<Rectangle>(size);
        Body bodyA(std::move(bodyDefinition));

        bodyDefinition.shape = std::make_unique<Circle>(radius);
        bodyDefinition.transform.position = Vector2f(5, 0);
        Body bodyB(std::move(bodyDefinition));

        const auto actual = collisionHandler.hasCollision(&bodyA, &bodyB);
        const auto expected = false;
        EXPECT_EQ(expected, actual);
    }

    TEST_F(CollisionDetectionTest, CircleAndRectangleHaveHorizontalCollision) {
        const Vector2f size(2, 2);
        const auto radius = 1.f;

        bodyDefinition.shape = std::make_unique<Rectangle>(size);
        Body bodyA(std::move(bodyDefinition));

        bodyDefinition.shape = std::make_unique<Circle>(radius);
        bodyDefinition.transform.position = Vector2f(1.5, 0);
        Body bodyB(std::move(bodyDefinition));

        const auto actual = collisionHandler.hasCollision(&bodyA, &bodyB);
        const auto expected = true;
        EXPECT_EQ(expected, actual);
    }

    TEST_F(CollisionDetectionTest, CircleAndRectangleHaveDiagonalCollision) {
        const Vector2f size(2, 2);
        const auto radius = 1.8f;

        bodyDefinition.shape = std::make_unique<Rectangle>(size);
        Body bodyA(std::move(bodyDefinition));

        bodyDefinition.shape = std::make_unique<Circle>(radius);
        bodyDefinition.transform.position = Vector2f(2, 2);
        Body bodyB(std::move(bodyDefinition));

        const auto actual = collisionHandler.hasCollision(&bodyA, &bodyB);
        const auto expected = true;
        EXPECT_EQ(expected, actual);
    }

}  // namespace AnimeDefendersEngine::Physics
