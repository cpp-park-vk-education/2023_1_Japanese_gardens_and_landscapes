#pragma once
#include <concepts>

namespace AnimeDefendersEngine {
    namespace Math {
        template <typename T>
        concept Number = std::integral<T> || std::floating_point<T>;

        template <Number T>
        class Coords2d {
         public:
            explicit Coords2d(T x, T y) {}
            auto getX() const -> T& {}
            auto getY() const -> T& {}

         private:
            T m_xCoord;
            T m_yCoord;
        };

    }  // namespace Math
}  // namespace AnimeDefendersEngine
