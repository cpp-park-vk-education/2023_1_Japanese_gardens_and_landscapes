#include "Logger.hpp"

#include <chrono>
#include <ctime>
#include <fstream>

namespace {
    struct CurrentTime {};

    auto operator<<(std::ostream& stream, [[maybe_unused]] CurrentTime) -> std::ostream& {
        auto timePoint = std::chrono::system_clock::now();
        auto t = std::chrono::system_clock::to_time_t(timePoint);
        std::tm* now = std::localtime(&t);
        stream << now->tm_hour << ':' << now->tm_min << ':' << now->tm_sec << " " << now->tm_mday << '.' << (now->tm_mon + 1) << '.'
               << (now->tm_year + 1900);

        return stream;
    }
}  // namespace

using AnimeDefendersEngine::Logger::BasicLogger;

auto BasicLogger::printMessage(const std::string& message) -> BasicLogger& {
    if (m_logLevel >= LogLevel::ErrorsWarningsAndMessages) {
        (*m_stream) << "Message [" << CurrentTime{} << "] " << message << '\n';
    }
    return *this;
}

auto BasicLogger::printWarning(const std::string& message) -> BasicLogger& {
    auto yellowColor = "\033[1;33m";
    auto noColor = "\033[0m";
    if (m_logLevel >= LogLevel::ErrorsAndWarnings) {
        (*m_stream) << yellowColor << "Warning [" << CurrentTime{} << "] " << message << noColor << '\n';
    }

    return *this;
}

auto BasicLogger::printError(const std::string& message) -> BasicLogger& {
    auto redColor = "\033[1;31m";
    auto noColor = "\033[0m";
    if (m_logLevel >= LogLevel::OnlyErrors) {
        (*m_stream) << redColor << "Error [" << CurrentTime{} << "] " << message << noColor << '\n';
    }

    return *this;
}

auto BasicLogger::setLogLevel(LogLevel logLevel) noexcept -> void {
    m_logLevel = logLevel;
}

namespace AnimeDefendersEngine::Logger {

    BasicLogger defaultLog{std::move(std::make_unique<std::ofstream>("log.txt"))};

}  // namespace AnimeDefendersEngine::Logger
