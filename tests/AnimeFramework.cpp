#include "Logger.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(SampleTest, TestSoThisFileWontBeEmpty) {
    using namespace AnimeDefendersEngine::Logger;
    defaultLog.setLogLevel(LogLevel::NoLog);
    ASSERT_TRUE(true);
}
