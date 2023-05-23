#pragma once

#include <string>

namespace AnimeDefendersEngine::Physics {

    enum class ContactEventType {
        ContactEnter,
        ContactStay,
        ContactExit
    };

    struct ContactEvent {
        std::string bodyAID;
        std::string bodyBID;
        ContactEventType type;
    };

}  // namespace AnimeDefendersEngine::Physics