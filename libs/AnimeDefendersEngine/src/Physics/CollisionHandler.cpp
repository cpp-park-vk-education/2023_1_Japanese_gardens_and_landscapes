#include "CollisionHandler.hpp"
#include "Body.hpp"
#include "Manifold.hpp"
#include "Vector2.hpp"

#include <cmath>

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
        const auto distance = (bodyA->getPosition() - bodyB->getPosition()).norm();
        return distance < circleA->radius + circleB->radius;
    }

    auto hasCollisionRectangleCircle(Body* bodyA, Body* bodyB) -> bool {
        const auto rectangleA = dynamic_cast<Rectangle*>(bodyA->getShape());
        const auto circleB = dynamic_cast<Circle*>(bodyB->getShape());

        const auto distance = bodyB->getPosition() - bodyA->getPosition();
        auto closestVertexToCircleCenter = distance;
        const auto xExtent = rectangleA->size.x / 2;
        const auto yExtent = rectangleA->size.y / 2;

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
        const auto rectangleA = dynamic_cast<Rectangle*>(bodyA->getShape());
        const auto rectangleB = dynamic_cast<Rectangle*>(bodyB->getShape());

        const auto normal = bodyB->getPosition() - bodyA->getPosition();
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

namespace {

    auto specifyCollisionCircleCircle(Manifold& contact) -> void {
        const auto circleA = dynamic_cast<Circle*>(contact.bodyA);
        const auto circleB = dynamic_cast<Circle*>(contact.bodyB);
        auto direction = contact.bodyB->getPosition() - contact.bodyA->getPosition();
        const auto distance = direction.norm();
        const auto totalRadius = circleA->radius + circleB->radius;
        contact.penetration = totalRadius - distance;
        contact.normal = (1.f / distance) * direction;
    }

    auto specifyCollisionRectangleCircle(Manifold& contact) -> void {
        const auto rectangleA = dynamic_cast<Rectangle*>(contact.bodyA->getShape());
        const auto circleB = dynamic_cast<Circle*>(contact.bodyB->getShape());

        auto distance = contact.bodyB->getPosition() - contact.bodyA->getPosition();
        auto closestVertexToCircleCenter = distance;
        const auto xExtent = rectangleA->size.x / 2;
        const auto yExtent = rectangleA->size.y / 2;

        closestVertexToCircleCenter.x = std::min(closestVertexToCircleCenter.x, xExtent);
        closestVertexToCircleCenter.x = std::max(closestVertexToCircleCenter.x, -xExtent);
        closestVertexToCircleCenter.y = std::min(closestVertexToCircleCenter.y, yExtent);
        closestVertexToCircleCenter.y = std::max(closestVertexToCircleCenter.y, -yExtent);

        auto normal = distance - closestVertexToCircleCenter;
        contact.normal = normal;
        contact.penetration = circleB->radius - distance.norm();
    }

    auto specifyCollisionCircleRectangle(Manifold& contact) -> void {
        specifyCollisionRectangleCircle(contact);
    }

    auto specifyCollisionRectangleRectangle(Manifold& contact) -> void {
        const auto rectangleA = dynamic_cast<Rectangle*>(contact.bodyA->getShape());
        const auto rectangleB = dynamic_cast<Rectangle*>(contact.bodyB->getShape());

        auto direction = contact.bodyB->getPosition() - contact.bodyA->getPosition();
        const auto xOverlap = (rectangleA->size.x + rectangleB->size.x) / 2 - std::abs(direction.x);
        const auto yOverlap = (rectangleA->size.y + rectangleB->size.y) / 2 - std::abs(direction.y);

        if (xOverlap < yOverlap) {
            if (direction.x < 0) {
                contact.normal = AnimeDefendersEngine::Math::Vector2f(-1, 0);
            } else {
                contact.normal = AnimeDefendersEngine::Math::Vector2f(1, 0);
            }
            contact.penetration = xOverlap;
        } else {
            if (direction.y < 0) {
                contact.normal = AnimeDefendersEngine::Math::Vector2f(0, -1);
            } else {
                contact.normal = AnimeDefendersEngine::Math::Vector2f(0, 1);
            }
            contact.penetration = yOverlap;
        }
    }

    using specifyCollisionFunctionPtr = void (*)(Manifold& contact);

    specifyCollisionFunctionPtr specifyCollisionTypes[Shape::shapeCount][Shape::shapeCount] = {
        {specifyCollisionCircleCircle,    specifyCollisionCircleRectangle   },
        {specifyCollisionRectangleCircle, specifyCollisionRectangleRectangle}
    };

}  // namespace

auto CollisionHandler::specifyCollision(Manifold& contact) const -> void {
    specifyCollisionTypes[static_cast<int>(contact.bodyA->getShapeType())][static_cast<int>(contact.bodyB->getShapeType())](contact);
};

constexpr float correctionPercent = 0.5f;

auto CollisionHandler::resolveCollision(Manifold& contact) const -> void {
    using AnimeDefendersEngine::Math::Vector2f;

    const auto relativeVelocity = contact.bodyB->getVelocity() - contact.bodyA->getVelocity();
    const auto relativeVelocityProjection = relativeVelocity * contact.normal;

    if (relativeVelocityProjection > 0) {
        return;
    }

    const auto impulseMagnitude = -2 * relativeVelocityProjection / (contact.bodyA->getInverseMass() + contact.bodyB->getInverseMass());
    Vector2f impulse = impulseMagnitude * contact.normal;

    contact.bodyA->setVelocity(contact.bodyA->getVelocity() - contact.bodyA->getInverseMass() * impulse);
    contact.bodyB->setVelocity(contact.bodyB->getVelocity() + contact.bodyB->getInverseMass() * impulse);

    contact.correctPositions();
}
