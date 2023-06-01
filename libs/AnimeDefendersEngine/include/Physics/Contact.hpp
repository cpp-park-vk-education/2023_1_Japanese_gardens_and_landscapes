#pragma once

#include <string>

namespace AnimeDefendersEngine::Physics {

    struct Contact {
        Contact(const std::string& bodyAID, const std::string& bodyBID) : bodyAID(bodyAID), bodyBID(bodyBID){};
        Contact() = default;

        friend auto operator==(const Contact& left, const Contact& right) -> bool;

        std::string bodyAID;
        std::string bodyBID;
    };

}  // namespace AnimeDefendersEngine::Physics

namespace std {

    template <>
    struct hash<AnimeDefendersEngine::Physics::Contact> {
        size_t operator()(const AnimeDefendersEngine::Physics::Contact& contact) const {
            return hash<string>()(contact.bodyAID) ^ hash<string>()(contact.bodyBID);
        }
    };

}  // namespace std
