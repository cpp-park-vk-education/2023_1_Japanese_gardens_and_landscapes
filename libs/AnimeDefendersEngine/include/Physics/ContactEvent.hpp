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
        ContactEvent(std::string bodyAID, std::string bodyBID, ContactEventType type)
            : bodyAID(std::move(bodyAID)), bodyBID(std::move(bodyBID)), type(type){};
        ContactEvent() = default;
        std::string bodyAID;
        std::string bodyBID;
        ContactEventType type;
    };

}  // namespace AnimeDefendersEngine::Physics
