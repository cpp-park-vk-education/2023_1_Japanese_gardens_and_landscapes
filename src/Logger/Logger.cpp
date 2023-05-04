#include "Logger.hpp"

#include <string>

using namespace AnimeDefendersEngine::Logger;

auto BasicLogger::operator<<(const std::string&) -> BasicLogger& {}
