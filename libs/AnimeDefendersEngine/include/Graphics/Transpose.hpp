#pragma once

#include <array>

namespace AnimeDefendersEngine {

    struct Transpose {
        Transpose(std::array<double, 3> posCoords, double vecticalViewAngle, double horisontalViewAngle)
            : m_posCoords(posCoords), m_vecticalViewAngle(vecticalViewAngle), m_horisontalViewAngle(horisontalViewAngle) {}
        std::array<double, 3> m_posCoords{};
        double m_vecticalViewAngle{};
        double m_horisontalViewAngle{};
    };

}  // namespace AnimeDefendersEngine
