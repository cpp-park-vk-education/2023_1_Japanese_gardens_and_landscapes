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

        [[nodiscard]] inline auto operator<(LogLevel a, LogLevel b) noexcept -> bool {
            return static_cast<char>(a) < static_cast<char>(b);
        }

        class BasicLogger {
         public:
            explicit BasicLogger(std::unique_ptr<std::ostream>&& stream) : m_stream{std::move(stream)} {}

            auto operator<<(const std::string& message) -> BasicLogger&;

            auto printMessage(const std::string& message) -> BasicLogger&;
            auto printError(const std::string& message) -> BasicLogger&;
            auto printWarning(const std::string& message) -> BasicLogger&;

            void setLogLevel(LogLevel) noexcept;

         private:
            LogLevel m_logLevel{LogLevel::ErrorsWarningsAndMessages};
            std::unique_ptr<std::ostream> m_stream;
        };

        extern BasicLogger deafult_log;

    }  // namespace Logger
}  // namespace AnimeDefendersEngine
