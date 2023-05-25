#pragma once

#include <string>
#include <utility>

namespace AnimeDefendersEngine::Physics {

    enum class ContactEventType {
        ContactEnter,
        ContactStay,
        ContactExit
    };

    struct ContactEvent {
        ContactEvent(const std::string& bodyAID, const std::string& bodyBID, ContactEventType type)
            : bodyAID(bodyAID), bodyBID(bodyBID), type(type){};
        ContactEvent() = default;

        std::string bodyAID;
        std::string bodyBID;
        ContactEventType type;
    };

}  // namespace AnimeDefendersEngine::Physics
