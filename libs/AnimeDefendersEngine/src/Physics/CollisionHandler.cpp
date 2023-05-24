#include "CollisionHandler.hpp"
#include "Body.hpp"
#include "Manifold.hpp"
#include "Vector2.hpp"

#include <cmath>
#include <functional>

namespace AnimeDefendersEngine::Physics {

    auto CollisionHandler::broadPhase(const std::vector<Body*>& bodies) const -> std::unordered_set<Manifold> {
        std::unordered_set<Manifold> contacts;
        contacts.reserve(bodies.size());
        for (auto bodyAIter = bodies.begin(); bodyAIter != bodies.end(); ++bodyAIter) {
            for (auto bodyBIter = std::next(bodyAIter); bodyBIter != bodies.end(); ++bodyBIter) {
                if ((*bodyAIter)->getID() < (*bodyBIter)->getID()) {
                    contacts.emplace(*bodyAIter, *bodyBIter);
                } else {
                    contacts.emplace(*bodyBIter, *bodyAIter);
                }
            }
        }
        return contacts;
    }

    auto CollisionHandler::narrowPhase(std::unordered_set<Manifold>& contacts) const -> void {
        for (auto contactIterator = contacts.begin(); contactIterator != contacts.end();) {
            auto contact = *contactIterator;
            contacts.erase(contactIterator);
            if (hasCollision(contact.bodyA, contact.bodyB)) {
                if (contact.bodyA->isTrigger() || contact.bodyB->isTrigger()) {
                    continue;
                }
                specifyCollision(contact);
                resolveCollision(contact);
                contacts.insert(contact);
                ++contactIterator;
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

            const auto normal = distance - closestVertexToCircleCenter;

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

        using HasCollisionFunction = std::function<bool(Body*, Body*)>;

        /// \details Массив функций проверки коллизий. В позиции (i, j) проверка коллизии формы i с формой j
        HasCollisionFunction hasCollisionTypes[Shape::shapeCount][Shape::shapeCount] = {
            {hasCollisionCircleCircle,    hasCollisionCircleRectangle   },
            {hasCollisionRectangleCircle, hasCollisionRectangleRectangle}
        };

    }  // namespace

    auto CollisionHandler::hasCollision(Body* bodyA, Body* bodyB) const -> bool {
        const auto typeA = static_cast<int>(bodyA->getShapeType());
        const auto typeB = static_cast<int>(bodyB->getShapeType());
        return hasCollisionTypes[typeA][typeB](bodyA, bodyB);
    }

    namespace {

        auto specifyCollisionCircleCircle(Manifold& contact) -> void {
            const auto circleA = dynamic_cast<Circle*>(contact.bodyA);
            const auto circleB = dynamic_cast<Circle*>(contact.bodyB);
            const auto direction = contact.bodyB->getPosition() - contact.bodyA->getPosition();
            const auto distance = direction.norm();
            const auto totalRadius = circleA->radius + circleB->radius;
            contact.penetration = totalRadius - distance;
            contact.normal = (1.f / distance) * direction;
        }

        auto specifyCollisionRectangleCircle(Manifold& contact) -> void {
            const auto rectangleA = dynamic_cast<Rectangle*>(contact.bodyA->getShape());
            const auto circleB = dynamic_cast<Circle*>(contact.bodyB->getShape());

            const auto distance = contact.bodyB->getPosition() - contact.bodyA->getPosition();
            auto closestVertexToCircleCenter = distance;
            const auto xExtent = rectangleA->size.x / 2;
            const auto yExtent = rectangleA->size.y / 2;

            closestVertexToCircleCenter.x = std::min(closestVertexToCircleCenter.x, xExtent);
            closestVertexToCircleCenter.x = std::max(closestVertexToCircleCenter.x, -xExtent);
            closestVertexToCircleCenter.y = std::min(closestVertexToCircleCenter.y, yExtent);
            closestVertexToCircleCenter.y = std::max(closestVertexToCircleCenter.y, -yExtent);

            contact.normal = distance - closestVertexToCircleCenter;
            contact.penetration = circleB->radius - distance.norm();
        }

        auto specifyCollisionCircleRectangle(Manifold& contact) -> void {
            specifyCollisionRectangleCircle(contact);
        }

        auto specifyCollisionRectangleRectangle(Manifold& contact) -> void {
            using AnimeDefendersEngine::Math::Vector2f;

            const auto rectangleA = dynamic_cast<Rectangle*>(contact.bodyA->getShape());
            const auto rectangleB = dynamic_cast<Rectangle*>(contact.bodyB->getShape());

            const auto direction = contact.bodyB->getPosition() - contact.bodyA->getPosition();
            const auto xOverlap = (rectangleA->size.x + rectangleB->size.x) / 2 - std::abs(direction.x);
            const auto yOverlap = (rectangleA->size.y + rectangleB->size.y) / 2 - std::abs(direction.y);

            if (xOverlap < yOverlap) {
                contact.normal = direction.x * Vector2f(1, 0);
                contact.penetration = xOverlap;
            } else {
                contact.normal = direction.y * Vector2f(0, 1);
                contact.penetration = yOverlap;
            }
        }

        using SpecifyCollisionFunction = std::function<void(Manifold&)>;

        SpecifyCollisionFunction specifyCollisionTypes[Shape::shapeCount][Shape::shapeCount] = {
            {specifyCollisionCircleCircle,    specifyCollisionCircleRectangle   },
            {specifyCollisionRectangleCircle, specifyCollisionRectangleRectangle}
        };

    }  // namespace

    auto CollisionHandler::specifyCollision(Manifold& contact) const -> void {
        const auto typeA = static_cast<int>(contact.bodyA->getShapeType());
        const auto typeB = static_cast<int>(contact.bodyB->getShapeType());
        specifyCollisionTypes[typeA][typeB](contact);
    };

    namespace {

        constexpr float correctionPercent = 0.5f;

    }

    auto CollisionHandler::resolveCollision(Manifold& contact) const -> void {
        const auto relativeVelocity = contact.bodyB->getVelocity() - contact.bodyA->getVelocity();
        const auto relativeVelocityProjection = relativeVelocity * contact.normal;

        if (relativeVelocityProjection > 0) {
            return;
        }

        const auto impulseMagnitude = -2 * relativeVelocityProjection / (contact.bodyA->getInverseMass() + contact.bodyB->getInverseMass());
        const auto impulse = impulseMagnitude * contact.normal;

        contact.bodyA->setVelocity(contact.bodyA->getVelocity() - contact.bodyA->getInverseMass() * impulse);
        contact.bodyB->setVelocity(contact.bodyB->getVelocity() + contact.bodyB->getInverseMass() * impulse);

        contact.correctPositions();
    }

}  // namespace AnimeDefendersEngine::Physics
