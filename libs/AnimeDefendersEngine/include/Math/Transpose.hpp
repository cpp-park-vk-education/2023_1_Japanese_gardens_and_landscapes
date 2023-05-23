#pragma once

#include "Coords3d.hpp"

namespace AnimeDefendersEngine::Math {

    struct Transpose {
        Coords3d posCoords{};
        double vecticalViewAngle{};
        double horisontalViewAngle{};
    };

}  // namespace AnimeDefendersEngine::Math
