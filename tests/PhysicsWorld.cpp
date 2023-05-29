#include "PhysicsWorld.hpp"
#include "Body.hpp"
#include "CollisionHandler.hpp"
#include "Vector2.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>

namespace AnimeDefendersEngine::Physics {

    using AnimeDefendersEngine::Math::Vector2f;

    class PhysicsWorldTest : public testing::Test {
     protected:
        void SetUp() override {
            physicsWorld = std::make_unique<PhysicsWorld>(std::make_unique<CollisionHandler>());
            physicsWorld->setFixedDeltaTime(0.1f);
        }

        void TearDown() override {}

        std::unique_ptr<PhysicsWorld> physicsWorld;
        BodyDefinition bodyDefinition;
    };

    TEST_F(PhysicsWorldTest, AddedCircleHaveRightShapeType) {
        const auto radius = 1.f;
        bodyDefinition.shape = std::make_unique<Circle>(radius);

        Body* body = physicsWorld->addBody(std::move(bodyDefinition));

        const auto actual = body->getShapeType();
        auto expected = ShapeType::circle;
        EXPECT_EQ(expected, actual);
    }

    TEST_F(PhysicsWorldTest, AddedRectangleHaveRightShapeType) {
        Vector2f size(1, 1);
        bodyDefinition.shape = std::make_unique<Rectangle>(size);

        Body* body = physicsWorld->addBody(std::move(bodyDefinition));

        const auto actual = body->getShapeType();
        auto expected = ShapeType::rectangle;
        EXPECT_EQ(expected, actual);
    }

    TEST_F(PhysicsWorldTest, PhysicsWorldRegistersContactOfTwoCircles) {
        const auto radius = 1.f;

        bodyDefinition.shape = std::make_unique<Circle>(radius);
        bodyDefinition.id = "A";
        Body* circleA = physicsWorld->addBody(std::move(bodyDefinition));

        bodyDefinition.shape = std::make_unique<Circle>(radius);
        bodyDefinition.transform.position = Vector2f(0, 1);
        bodyDefinition.id = "B";
        Body* circleB = physicsWorld->addBody(std::move(bodyDefinition));

        const auto events = physicsWorld->fixedUpdate();
        const auto actual_size = events.size();
        auto expected_size = 1;
        EXPECT_EQ(expected_size, actual_size);
        EXPECT_EQ(events.begin()->bodyAID, "A");
        EXPECT_EQ(events.begin()->bodyBID, "B");
        EXPECT_EQ(events.begin()->type, ContactEventType::ContactEnter);
    }

}  // namespace AnimeDefendersEngine::Physics