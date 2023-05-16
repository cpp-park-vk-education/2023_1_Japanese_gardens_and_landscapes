#include "CollisionHandler.hpp"
#include "Body.hpp"
#include "Vector2.hpp"

using namespace AnimeDefendersEngine::Physics;

auto CollisionHandler::broadPhase(const std::vector<IBody*>& bodies) -> std::vector<Manifold> {
    std::vector<Manifold> contacts(bodies.size());
    for (size_t i = 0; i < bodies.size(); ++i) {
        IBody* bodyA = bodies.at(i);
        for (size_t j = i + 1; j < bodies.size(); ++j) {
            IBody* bodyB = bodies.at(i);
            Manifold contact(bodyA, bodyB);
            contacts.push_back(contact);
        }
    }
    return contacts;
}

auto CollisionHandler::narrowPhase(std::vector<Manifold>& contacts) -> void {
    for (auto contactIterator = contacts.begin(); contactIterator != contacts.end();) {
        if (hasCollision(contactIterator->bodyA, contactIterator->bodyB)) {
            if (contactIterator->bodyA->isTrigger() || contactIterator->bodyB->isTrigger()) {
                continue;
            }
            specifyCollision(*contactIterator);
            resolveCollision(*contactIterator);
            contactIterator++;
        } else {
            contacts.erase(contactIterator);
        }
    }
};

static auto hasCollisionCircleCircle(IBody* bodyA, IBody* bodyB) -> bool {
    Circle* circleA = dynamic_cast<Circle*>(bodyA->getShape());
    Circle* circleB = dynamic_cast<Circle*>(bodyB->getShape());
    float distance = (bodyA->getPosition() - bodyB->getPosition()).norm();
    return distance < circleA->radius + circleB->radius;
}

static auto hasCollisionRectangleCircle(IBody* bodyA, IBody* bodyB) -> bool {
    Rectangle* rectangleA = dynamic_cast<Rectangle*>(bodyA->getShape());
    Circle* circleB = dynamic_cast<Circle*>(bodyB->getShape());
    AnimeDefendersEngine::Math::Vector2<float> distance = bodyB->getPosition() - bodyA->getPosition();
    AnimeDefendersEngine::Math::Vector2<float> closestVertexToCircleCenter = distance;
    float x_extent = rectangleA->size.x / 2;
    float y_extent = rectangleA->size.y / 2;
    closestVertexToCircleCenter.x = std::min(closestVertexToCircleCenter.x, x_extent);
    closestVertexToCircleCenter.x = std::max(closestVertexToCircleCenter.x, -x_extent);
    closestVertexToCircleCenter.y = std::min(closestVertexToCircleCenter.y, y_extent);
    closestVertexToCircleCenter.y = std::max(closestVertexToCircleCenter.y, -y_extent);

    AnimeDefendersEngine::Math::Vector2<float> normal = distance - closestVertexToCircleCenter;

    return normal.norm() < circleB->radius;
};

static auto hasCollisionCircleRectangle(IBody* bodyA, IBody* bodyB) -> bool {
    return hasCollisionRectangleCircle(bodyB, bodyA);
};

static auto hasCollisionRectangleRectangle(IBody* bodyA, IBody* bodyB) -> bool {
    Rectangle* rectangleA = dynamic_cast<Rectangle*>(bodyA->getShape());
    Rectangle* rectangleB = dynamic_cast<Rectangle*>(bodyB->getShape());

    AnimeDefendersEngine::Math::Vector2<float> normal = bodyB->getPosition() - bodyA->getPosition();
    float xOverlap = (rectangleA->size.x + rectangleB->size.x) / 2 - normal.norm();
    return xOverlap > 0;
};

using hasCollisionFunctionPtr = bool (*)(IBody* bodyA, IBody* bodyB);

static hasCollisionFunctionPtr hasCollisionTypes[Shape::shapeCount][Shape::shapeCount] = {
    {hasCollisionCircleCircle,    hasCollisionCircleRectangle   },
    {hasCollisionRectangleCircle, hasCollisionRectangleRectangle}
};

auto CollisionHandler::hasCollision(IBody* bodyA, IBody* bodyB) -> bool {
    return hasCollisionTypes[bodyA->getShapeType()][bodyB->getShapeType()](bodyA, bodyB);
};

auto CollisionHandler::specifyCollision(Manifold& contact) -> void{

};

auto CollisionHandler::resolveCollision(Manifold& contact) -> void{

};
