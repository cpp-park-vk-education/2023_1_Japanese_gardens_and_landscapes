#include "A.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

class MockClass : public A::InnerClass {
 public:
    MOCK_METHOD(int, call, (int), (noexcept, override));
};

class MockSomeClass : public A::SomeClass {
    using A::SomeClass::SomeClass;

 public:
    MOCK_METHOD(int, sum, (short, short), (noexcept, override));
};

TEST(A_LIB, firstTest) {
    ASSERT_EQ('A', A::f());
}

TEST(A_LIB, mockSample) {
    MockClass mc{};
    A::SomeClass sc{&mc};
    EXPECT_CALL(mc, call(10));
    [[maybe_unused]] auto x = sc.sum(4, 6);
}

using ::testing::AtLeast;
TEST(A_LIB, mockSecodn) {
    MockSomeClass mc{nullptr};
    EXPECT_CALL(mc, sum(10, 13)).Times(AtLeast(2));

    [[maybe_unused]] auto x = mc.indirectSum(10, 13);
    x = mc.indirectSum(10, 13);
    x = mc.indirectSum(10, 13);
    x = mc.indirectSum(10, 13);
}
