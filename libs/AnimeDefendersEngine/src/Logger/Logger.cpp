#include "Logger.hpp"

using namespace AnimeDefendersEngine::Logger;

auto BasicLogger::operator<<(const std::string&) -> BasicLogger* {
    return nullptr;
}
