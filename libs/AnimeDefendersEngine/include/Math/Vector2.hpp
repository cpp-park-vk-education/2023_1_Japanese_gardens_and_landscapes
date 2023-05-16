#pragma once

namespace AnimeDefendersEngine {
    namespace Math {

        template <typename T>
        struct Vector2 {
            explicit Vector2(T val1 = T{}, T val2 = T{});
            auto norm() -> T&;
            T x;
            T y;

            friend auto operator+(const Vector2& vec1, const Vector2& vec2) -> Vector2&;
            friend auto operator-(const Vector2& vec1, const Vector2& vec2) -> Vector2&;
            friend auto operator*(const Vector2& vec1, const Vector2& vec2) -> T&;
            friend auto operator*(const T& const1, const Vector2& vec1) -> Vector2&;
        };

    }  // namespace Math
}  // namespace AnimeDefendersEngine
