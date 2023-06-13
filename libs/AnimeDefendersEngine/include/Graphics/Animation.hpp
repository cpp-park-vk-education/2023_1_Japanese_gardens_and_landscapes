#pragma once

#include "Texture.hpp"

#include <vector>

namespace AnimeDefendersEngine {
    namespace Graphics {

        struct Animation {
            std::vector<Texture> frames;
            int timeInterval;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
