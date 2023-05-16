#include "Logger.hpp"

#include <chrono>

using namespace AnimeDefendersEngine::Logger;

auto BasicLogger::operator<<(const std::string& message) -> BasicLogger& {

    (*m_stream) << message;
    return *this;
}

auto BasicLogger::printMessage(const std::string& message) -> BasicLogger& {
    return *this;
}

auto BasicLogger::printWarning(const std::string& message) -> BasicLogger& {
    return *this;
}

auto BasicLogger::printError(const std::string& message) -> BasicLogger& {
    return *this;
}
