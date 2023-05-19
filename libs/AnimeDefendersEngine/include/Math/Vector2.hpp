#pragma once

namespace AnimeDefendersEngine {
    namespace Math {
        template <typename T>
        struct Vector2;
        template <typename T>
        auto operator+(const Vector2<T>& vec1, const Vector2<T>& vec2) -> Vector2<T>{};
        template <typename T>
        auto operator-(const Vector2<T>& vec1, const Vector2<T>& vec2) -> Vector2<T>{};
        template <typename T>
        auto operator*(const Vector2<T>& vec1, const Vector2<T>& vec2) -> T{};
        template <typename T>
        auto operator*(const T& const1, const Vector2<T>& vec1) -> Vector2<T>{};

        template <typename T>
        struct Vector2 {
            explicit Vector2(T val1 = T{}, T val2 = T{});
            auto norm() -> T&;
            T x;
            T y;

            friend auto operator+<T>(const Vector2<T>& vec1, const Vector2<T>& vec2) -> Vector2<T>;

            friend auto operator-<T>(const Vector2<T>& vec1, const Vector2<T>& vec2) -> Vector2<T>;

            friend auto operator*<T>(const Vector2<T>& vec1, const Vector2<T>& vec2) -> T;

            friend auto operator*<T>(const T& const1, const Vector2<T>& vec1) -> Vector2<T>;
        };

        using Vector2f = Vector2<float>;

    }  // namespace Math
}  // namespace AnimeDefendersEngine
