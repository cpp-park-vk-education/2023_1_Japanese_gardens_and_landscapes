#pragma once

namespace AnimeDefendersEngine {
    namespace Math {

        template <typename T>
        struct Vector2 {
            explicit Vector2(T val1 = T{}, T val2 = T{});
            auto norm() -> T&;
            auto operator+(const Vector2& vec1) -> Vector2&;
            auto operator-(const Vector2& vec1) -> Vector2&;
            auto operator*(const Vector2& vec1) -> T&;
            auto operator*(const T& const1) -> Vector2&;
            T x;
            T y;
        };

    }  // namespace Math
}  // namespace AnimeDefendersEngine
