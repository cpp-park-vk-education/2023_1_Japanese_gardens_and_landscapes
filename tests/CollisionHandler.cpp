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

    TEST(CollisionDetectionTest, TwoCirclesDontHaveCollision) {
        using namespace AnimeDefendersEngine::Physics;
        using AnimeDefendersEngine::Math::Vector2f;

        const auto radius = 1.f;

        BodyDefinition defA;
        defA.shape = std::make_unique<Circle>(radius);
        defA.transform.position = Vector2f(0, 0);
        Body bodyA(std::move(defA));

        BodyDefinition defB;
        defB.shape = std::make_unique<Circle>(radius);
        defB.transform.position = Vector2f(2.1f * radius, 0);
        Body bodyB(std::move(defB));

        CollisionHandler CollisionHandler;
        const auto actual = CollisionHandler.hasCollision(&bodyA, &bodyB);
        const auto expected = false;

        EXPECT_EQ(expected, actual);
    }

    TEST(CollisionDetectionTest, TwoRectanglesDontHaveCollision) {
        using namespace AnimeDefendersEngine::Physics;
        using AnimeDefendersEngine::Math::Vector2f;

        const Vector2f size(1, 1);

        BodyDefinition defA;
        defA.shape = std::make_unique<Rectangle>(size);
        defA.transform.position = Vector2f(0, 0);
        Body bodyA(std::move(defA));

        BodyDefinition defB;
        defB.shape = std::make_unique<Rectangle>(size);
        defB.transform.position = Vector2f(2, 0);
        Body bodyB(std::move(defB));

        CollisionHandler CollisionHandler;
        const auto actual = CollisionHandler.hasCollision(&bodyA, &bodyB);
        const auto expected = false;

        EXPECT_EQ(expected, actual);
    }

    TEST(CollisionDetectionTest, TwoRectanglesHaveHorizontalCollision) {
        using namespace AnimeDefendersEngine::Physics;
        using AnimeDefendersEngine::Math::Vector2f;

        const Vector2f size(2, 2);

        BodyDefinition defA;
        defA.shape = std::make_unique<Rectangle>(size);
        defA.transform.position = Vector2f(0, 0);
        Body bodyA(std::move(defA));

        BodyDefinition defB;
        defB.shape = std::make_unique<Rectangle>(size);
        defB.transform.position = Vector2f(1, 0);
        Body bodyB(std::move(defB));

        CollisionHandler CollisionHandler;
        const auto actual = CollisionHandler.hasCollision(&bodyA, &bodyB);
        const auto expected = true;

        EXPECT_EQ(expected, actual);
    }

    TEST(CollisionDetectionTest, TwoRectanglesHaveDiagonalCollision) {
        using namespace AnimeDefendersEngine::Physics;
        using AnimeDefendersEngine::Math::Vector2f;

        const Vector2f size(2, 2);

        BodyDefinition defA;
        defA.shape = std::make_unique<Rectangle>(size);
        defA.transform.position = Vector2f(0, 0);
        Body bodyA(std::move(defA));

        BodyDefinition defB;
        defB.shape = std::make_unique<Rectangle>(size);
        defB.transform.position = Vector2f(1.5f, 1.5f);
        Body bodyB(std::move(defB));

        CollisionHandler CollisionHandler;
        const auto actual = CollisionHandler.hasCollision(&bodyA, &bodyB);
        const auto expected = true;

        EXPECT_EQ(expected, actual);
    }

    TEST(CollisionDetectionTest, TwoRectanglesDontHaveCollisionBecauseTheyHaveTheSameCenter) {
        using namespace AnimeDefendersEngine::Physics;
        using AnimeDefendersEngine::Math::Vector2f;

        const Vector2f position(10, 10);

        BodyDefinition defA;
        defA.shape = std::make_unique<Rectangle>(Vector2f(100, 2));
        defA.transform.position = position;
        Body bodyA(std::move(defA));

        BodyDefinition defB;
        defB.shape = std::make_unique<Rectangle>(Vector2f(2, 100));
        defB.transform.position = position;
        Body bodyB(std::move(defB));

        CollisionHandler CollisionHandler;
        const auto actual = CollisionHandler.hasCollision(&bodyA, &bodyB);
        const auto expected = true;

        EXPECT_EQ(expected, actual);
    }

    TEST(CollisionDetectionTest, CircleAndRectangleDontHaveCollision) {
        using namespace AnimeDefendersEngine::Physics;
        using AnimeDefendersEngine::Math::Vector2f;

        const Vector2f size(1, 1);
        const auto radius = 4.f;

        BodyDefinition defA;
        defA.shape = std::make_unique<Rectangle>(size);
        Body bodyA(std::move(defA));

        BodyDefinition defB;
        defB.shape = std::make_unique<Circle>(radius);
        defB.transform.position = Vector2f(5, 0);
        Body bodyB(std::move(defB));

        CollisionHandler CollisionHandler;
        const auto actual = CollisionHandler.hasCollision(&bodyA, &bodyB);
        const auto expected = false;

        EXPECT_EQ(expected, actual);
    }

}  // namespace AnimeDefendersEngine::Physics
