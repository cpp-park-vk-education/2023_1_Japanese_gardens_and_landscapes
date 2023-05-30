#include "CollisionHandler.hpp"
#include "Body.hpp"
#include "Manifold.hpp"
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

    class CollisionBroadPhaseTest : public testing::Test {
     protected:
        void SetUp() override {
            const auto radius = 1.f;
            for (int i = 0; i < 4; ++i) {
                bodyDefinition.shape = std::make_unique<Circle>(radius);
                bodyDefinition.id = std::to_string(i);
                bodies.push_back(new Body(std::move(bodyDefinition)));
            }
        }

        void TearDown() override {
            for (auto& body : bodies) {
                delete body;
            }
        }

        std::vector<Body*> bodies;
        CollisionHandler collisionHandler;
        BodyDefinition bodyDefinition;
    };

    TEST_F(CollisionBroadPhaseTest, FourObjects) {
        const auto contacts = collisionHandler.broadPhase(bodies);
        const std::size_t expected_size = 6;
        const auto actual_size = contacts.size();
        EXPECT_EQ(expected_size, actual_size);
    }

    TEST_F(CollisionBroadPhaseTest, FiveObjects) {
        bodyDefinition.shape = std::make_unique<Circle>(1);
        bodyDefinition.id = std::to_string(5);
        bodies.push_back(new Body(std::move(bodyDefinition)));

        const auto contacts = collisionHandler.broadPhase(bodies);
        const std::size_t expected_size = 10;
        const auto actual_size = contacts.size();
        EXPECT_EQ(expected_size, actual_size);
    }

    TEST_F(CollisionBroadPhaseTest, ContactsIncludeCollidedObjects) {
        const auto contacts = collisionHandler.broadPhase(bodies);
        const bool actual = contacts.contains(Manifold(bodies.at(0), bodies.at(1)));
        const bool expected = true;
        EXPECT_EQ(expected, actual);
    }

    TEST_F(CollisionBroadPhaseTest, ContactsDoesntIncludeNotCollidedObjects) {
        const auto contacts = collisionHandler.broadPhase(bodies);
        const bool actual = contacts.contains(Manifold(bodies.at(0), bodies.at(0)));
        const bool expected = false;
        EXPECT_EQ(expected, actual);
    }

    class CollisionNarrowPhaseTest : public testing::Test {
     protected:
        void SetUp() override {
            bodyDefinition.shape = std::make_unique<Circle>(smallRadius);
            bodyDefinition.id = "A";
            smallCircle = std::make_unique<Body>(std::move(bodyDefinition));

            bodyDefinition.shape = std::make_unique<Circle>(bigRadius);
            bodyDefinition.transform.position = Vector2f(5, 0);
            bodyDefinition.id = "B";
            bigCircle = std::make_unique<Body>(std::move(bodyDefinition));

            Vector2f size(7, 4);
            bodyDefinition.shape = std::make_unique<Rectangle>(size);
            bodyDefinition.transform.position = Vector2f(0, 5);
            bodyDefinition.id = "C";
            rectangle = std::make_unique<Body>(std::move(bodyDefinition));

            contacts.emplace(smallCircle.get(), bigCircle.get());
            contacts.emplace(smallCircle.get(), rectangle.get());
            contacts.emplace(bigCircle.get(), rectangle.get());
        }

        void TearDown() override {}

        const float smallRadius{2.f};
        const float bigRadius{5.f};
        std::unique_ptr<Body> smallCircle;
        std::unique_ptr<Body> bigCircle;
        std::unique_ptr<Body> rectangle;

        std::unordered_set<Manifold> contacts;
        CollisionHandler collisionHandler;
        BodyDefinition bodyDefinition;
    };

    TEST_F(CollisionNarrowPhaseTest, NoContact) {
        std::unordered_set<Manifold> empty_contacts{};
        EXPECT_NO_THROW(collisionHandler.narrowPhase(empty_contacts));
    }

    TEST_F(CollisionNarrowPhaseTest, IdentifiedRightNumberOfContacts) {
        collisionHandler.narrowPhase(contacts);
        const auto actual_number = contacts.size();
        const auto expected_number = 2;
        EXPECT_EQ(expected_number, actual_number);
    }

    // TEST(normTest, test1) {
    //     Vector2f vec(1, 0);
    //     EXPECT_EQ(vec.norm(), 1);
    // }

    // TEST_F(CollisionNarrowPhaseTest, TwoCirclesCollisionResolvedSuccesfully) {
    //     collisionHandler.narrowPhase(contacts);

    //     for (auto contact : contacts) {
    //         if (contact.bodyA->getShapeType() == ShapeType::circle && contact.bodyB->getShapeType() == ShapeType::circle) {
    //             const auto actual_distance = contact.bodyB->getPosition() - contact.bodyA->getPosition();
    //             EXPECT_THAT((smallRadius + bigRadius) - actual_distance.norm(), ::testing::Lt(contact.penetration));
    //         }
    //     }
    //     //   const auto contacts = collisionHandler.broadPhase(bodies);
    //     //   const bool actual = contacts.contains(Manifold(bodies.at(0), bodies.at(0)));
    //     //   const bool expected = false;
    //     //   EXPECT_EQ(expected, actual);
    // }

}  // namespace AnimeDefendersEngine::Physics
