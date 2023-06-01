#pragma once

#include "Contact.hpp"

#include <string>
#include <utility>

namespace AnimeDefendersEngine::Physics {

    enum class ContactEventType {
        ContactEnter,
        ContactStay,
        ContactExit
    };

    struct ContactEvent {
        ContactEvent(const Contact& contact, ContactEventType type) : contact(contact), type(type){};
        ContactEvent() = default;

        Contact contact;
        ContactEventType type;
    };

}  // namespace AnimeDefendersEngine::Physics
