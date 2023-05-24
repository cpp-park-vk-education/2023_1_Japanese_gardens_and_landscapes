#pragma once

#include <string>

namespace AnimeDefendersEngine::Physics {

    enum class ContactEventType {
        ContactEnter,
        ContactStay,
        ContactExit
    };

    struct ContactEvent {
        ContactEvent(Body* bodyA, Body* bodyB, ContactEventType type) : bodyA(bodyA), bodyB(bodyB), type(type){};
        ContactEvent() = default;
        Body* bodyA{nullptr};
        Body* bodyB{nullptr};
        ContactEventType type;
    };

}  // namespace AnimeDefendersEngine::Physics