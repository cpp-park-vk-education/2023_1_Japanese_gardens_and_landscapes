#include "Contact.hpp"

#include <tuple>

namespace AnimeDefendersEngine::Physics {

    namespace {

        inline auto getIDs(const Contact& contact) {
            return std::tie(contact.bodyAID, contact.bodyBID);
        }

    }  // namespace

    auto operator==(const Contact& left, const Contact& right) -> bool {
        return getIDs(left) == getIDs(right);
    }

}  // namespace AnimeDefendersEngine::Physics
