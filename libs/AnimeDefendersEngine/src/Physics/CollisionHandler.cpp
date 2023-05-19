#include "CollisionHandler.hpp"
#include <cmath>
#include "Body.hpp"
#include "Vector2.hpp"

using namespace AnimeDefendersEngine::Physics;

auto CollisionHandler::broadPhase(const std::vector<Body*>& bodies) const -> std::vector<Manifold> {
    std::vector<Manifold> contacts;
    contacts.reserve(bodies.size());
    for (auto bodyAIter = bodies.begin(); bodyAIter != bodies.end(); ++bodyAIter) {
        for (auto bodyBIter = bodyAIter + 1; bodyBIter != bodies.end(); ++bodyBIter) {
            contacts.emplace_back(*bodyAIter, *bodyBIter);
        }
    }
    return contacts;
}

auto CollisionHandler::narrowPhase(std::vector<Manifold>& contacts) const -> void {
    for (auto contactIterator = contacts.begin(); contactIterator != contacts.end();) {
        if (hasCollision(contactIterator->bodyA, contactIterator->bodyB)) {
            if (contactIterator->bodyA->isTrigger() || contactIterator->bodyB->isTrigger()) {
                continue;
            }
            specifyCollision(*contactIterator);
            resolveCollision(*contactIterator);
            ++contactIterator;
        } else {
            contacts.erase(contactIterator);
        }
    }
}

namespace {

    auto hasCollisionCircleCircle(Body* bodyA, Body* bodyB) -> bool {
        const auto circleA = dynamic_cast<Circle*>(bodyA->getShape());
        const auto circleB = dynamic_cast<Circle*>(bodyB->getShape());
        float distance = (bodyA->getPosition() - bodyB->getPosition()).norm();
        return distance < circleA->radius + circleB->radius;
    }

    auto hasCollisionRectangleCircle(Body* bodyA, Body* bodyB) -> bool {
        const auto rectangleA = dynamic_cast<Rectangle*>(bodyA->getShape());
        const auto circleB = dynamic_cast<Circle*>(bodyB->getShape());

        const auto distance = bodyB->getPosition() - bodyA->getPosition();
        auto closestVertexToCircleCenter = distance;
        float xExtent = rectangleA->size.x / 2;
        float yExtent = rectangleA->size.y / 2;

        closestVertexToCircleCenter.x = std::min(closestVertexToCircleCenter.x, xExtent);
        closestVertexToCircleCenter.x = std::max(closestVertexToCircleCenter.x, -xExtent);
        closestVertexToCircleCenter.y = std::min(closestVertexToCircleCenter.y, yExtent);
        closestVertexToCircleCenter.y = std::max(closestVertexToCircleCenter.y, -yExtent);

        auto normal = distance - closestVertexToCircleCenter;

        return normal.norm() < circleB->radius;
    }

    auto hasCollisionCircleRectangle(Body* bodyA, Body* bodyB) -> bool {
        return hasCollisionRectangleCircle(bodyB, bodyA);
    }

    auto hasCollisionRectangleRectangle(Body* bodyA, Body* bodyB) -> bool {
        auto rectangleA = dynamic_cast<Rectangle*>(bodyA->getShape());
        auto rectangleB = dynamic_cast<Rectangle*>(bodyB->getShape());

        AnimeDefendersEngine::Math::Vector2<float> normal = bodyB->getPosition() - bodyA->getPosition();
        const auto xOverlap = (rectangleA->size.x + rectangleB->size.x) / 2 - std::abs(normal.x);
        if (xOverlap > 0) {
            const auto yOverlap = (rectangleA->size.y + rectangleB->size.y) / 2 - std::abs(normal.y);
            return yOverlap > 0;
        }
        return false;
    }

    using hasCollisionFunctionPtr = bool (*)(Body* bodyA, Body* bodyB);

    /// \details Массив указателей на функции проверки коллизий. В позиции (i, j) проверка коллизии формы i с формой j
    hasCollisionFunctionPtr hasCollisionTypes[Shape::shapeCount][Shape::shapeCount] = {
        {hasCollisionCircleCircle,    hasCollisionCircleRectangle   },
        {hasCollisionRectangleCircle, hasCollisionRectangleRectangle}
    };

}  // namespace

auto CollisionHandler::hasCollision(Body* bodyA, Body* bodyB) const -> bool {
    return hasCollisionTypes[static_cast<int>(bodyA->getShapeType())][static_cast<int>(bodyB->getShapeType())](bodyA, bodyB);
}

auto CollisionHandler::specifyCollision(Manifold& contact) const -> void {
    contact.penetration = 0;  // it was done for working CI
}

auto CollisionHandler::resolveCollision(Manifold& contact) const -> void {
    contact.penetration = 0;  // it was done for working CI
}
