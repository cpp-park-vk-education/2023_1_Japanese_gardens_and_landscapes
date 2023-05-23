#pragma once

#include <memory>
#include <ostream>
#include <string>

namespace AnimeDefendersEngine {
    namespace Logger {

        enum class LogLevel : char {
            NoLog = 0,
            OnlyErrors,
            ErrorsAndWarnings,
            ErrorsWarningsAndMessages
        };

        class BasicLogger {
         public:
            explicit BasicLogger(std::unique_ptr<std::ostream>&& stream);

            auto printMessage(const std::string& message) const -> const BasicLogger&;
            auto printError(const std::string& message) const -> const BasicLogger&;
            auto printWarning(const std::string& message) const -> const BasicLogger&;

            auto setLogLevel(LogLevel) noexcept -> void;

         private:
            LogLevel m_logLevel{LogLevel::ErrorsWarningsAndMessages};
            std::unique_ptr<std::ostream> m_stream;
        };

        extern BasicLogger defaultLog;

    }  // namespace Logger
}  // namespace AnimeDefendersEngine
