#pragma once

#include <string>

namespace AnimeDefendersEngine::Physics {

    enum class ContactEventType {
        ContactEnter,
        ContactStay,
        ContactExit
    };

    struct ContactEvent {
        ContactEvent(std::string bodyAID, std::string bodyDID, ContactEventType type) : bodyAID(bodyAID), bodyBID(bodyBID), type(type){};
        ContactEvent() = default;
        std::string bodyAID;
        std::string bodyBID;
        ContactEventType type;
    };

}  // namespace AnimeDefendersEngine::Physics
