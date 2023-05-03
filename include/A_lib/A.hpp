#include <iostream>
#pragma once

namespace A {
    auto f() -> char;

    class InnerClass {
     public:
        virtual auto call(int x) noexcept -> int = 0;
    };

    class SomeClass {
     public:
        explicit SomeClass(InnerClass* inner) noexcept : m_inner{inner} {}
        virtual auto sum(short a, short b) noexcept -> int {
            auto result = static_cast<int>(a + b);
            std::cout << result << std::endl;
            if (m_inner != nullptr) {
                return m_inner->call(result);
            }
            return result;
        };

        [[nodiscard]] auto indirectSum(short a, short b) -> int { return this->sum(a, b); }

     private:
        InnerClass* m_inner = nullptr;
    };
}  // namespace A