#pragma ones

#include "Texture.hpp"

#include <vector>

namespace AnimeDefendersEngine {

    struct Animation {
        std::vector<Texture> frames;
        int timeInterval;
    };

}  // namespace AnimeDefendersEngine
