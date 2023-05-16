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

auto CollisionHandler::specifyCollision(Manifold& contact) -> void{

};

auto CollisionHandler::resolveCollision(Manifold& contact) -> void{

};
