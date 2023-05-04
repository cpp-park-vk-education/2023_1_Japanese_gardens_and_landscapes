#pragma once

#include <string>

namespace AnimeDefendersEngine {

    namespace Logger {
        class BasicLogger {
         public:
            auto operator<<(const std::string&) -> BasicLogger&;
        };
        static_assert(false, "NoFinished");

        extern BasicLogger deafult_log;
    }  // namespace Logger
}  // namespace AnimeDefendersEngine