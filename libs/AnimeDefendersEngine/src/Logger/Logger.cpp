#include "Logger.hpp"

#include <chrono>
#include <ctime>
#include <fstream>
#include <iomanip>

namespace {

    constexpr auto redColor = "\033[1;31m";
    constexpr auto yellowColor = "\033[1;33m";
    constexpr auto noColor = "\033[0m";

}  // namespace

namespace {

    using AnimeDefendersEngine::Logger::LogLevel;
    [[nodiscard]] inline auto operator<(LogLevel a, LogLevel b) noexcept -> bool {
        return static_cast<char>(a) < static_cast<char>(b);
    }

    [[nodiscard]] auto currentTime() -> std::string {
        auto timePoint = std::chrono::high_resolution_clock::now();

        auto time = std::chrono::high_resolution_clock::to_time_t(timePoint);

        auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(timePoint.time_since_epoch()) % 1000;

        std::tm* now = std::localtime(&time);
        std::stringstream stream;
        stream << now->tm_hour << ':' << now->tm_min << ':' << now->tm_sec << ':' << std::setfill('0') << std::setw(3)
               << milliseconds.count() << " " << now->tm_mday << '.' << (now->tm_mon + 1) << '.' << (now->tm_year + 1900);

        return stream.str();
    }

}  // namespace

using AnimeDefendersEngine::Logger::BasicLogger;

BasicLogger::BasicLogger(std::unique_ptr<std::ostream>&& stream) : m_stream{std::move(stream)} {}

auto BasicLogger::printMessage(const std::string& message) const -> const BasicLogger& {
    if (m_logLevel >= LogLevel::ErrorsWarningsAndMessages) {
        *m_stream << "Message [" << currentTime() << "] " << message << '\n';
    }
    return *this;
}

auto BasicLogger::printWarning(const std::string& message) const -> const BasicLogger& {
    if (m_logLevel >= LogLevel::ErrorsAndWarnings) {
        *m_stream << yellowColor << "Warning [" << currentTime() << "] " << message << noColor << '\n';
    }

    return *this;
}

auto BasicLogger::printError(const std::string& message) const -> const BasicLogger& {
    if (m_logLevel >= LogLevel::OnlyErrors) {
        *m_stream << redColor << "Error   [" << currentTime() << "] " << message << noColor << '\n';
    }

    return *this;
}

auto BasicLogger::setLogLevel(LogLevel logLevel) noexcept -> void {
    m_logLevel = logLevel;
}

namespace AnimeDefendersEngine::Logger {

    BasicLogger defaultLog{std::move(std::make_unique<std::ofstream>("log.txt"))};

}  // namespace AnimeDefendersEngine::Logger
