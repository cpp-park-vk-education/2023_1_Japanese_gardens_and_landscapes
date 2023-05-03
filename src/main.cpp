#include "A.hpp"

#include <iostream>

auto subMain() -> int {
    std::cout << A::f() << std::endl;
    return 0;
}

auto main() -> int {
    return subMain();
}
