#include <iostream>
#include "AnimeFramework.hpp"

auto subMain() -> int {
    AnimeDefendersEngine::AnimeFramework game;
    game.run();
    return 0;
}

auto main() -> int {
    return subMain();
}
