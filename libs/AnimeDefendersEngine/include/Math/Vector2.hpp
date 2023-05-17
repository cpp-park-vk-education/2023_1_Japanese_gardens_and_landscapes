#pragma once

#include <iostream>
#include "math.h"

namespace AnimeDefendersEngine {
    namespace Math {

        template <typename T>
        struct Vector2 {
            explicit Vector2(T val1 = T{}, T val2 = T{}) : x(val1), y(val2) {}
            T x;
            T y;

            auto norm() -> T { return sqrt(this * this); }
            auto print() -> void { std::cout << "(" << x << ", " << y << ")" << std::endl; }
        };

        template <typename T>
        auto operator+(const Vector2<T>& vec1, const Vector2<T>& vec2) -> Vector2<T> {
            return Vector2<T>(vec1.x + vec2.x, vec1.y + vec2.y);
        }
        template <typename T>
        auto operator-(const Vector2<T>& vec1, const Vector2<T>& vec2) -> Vector2<T> {
            return Vector2<T>(vec1.x - vec2.x, vec1.y - vec2.y);
        }

        template <typename T>
        auto operator*(const Vector2<T>& vec1, const Vector2<T>& vec2) -> T {
            return vec1.x * vec2.x + vec1.y * vec2.y;
        }

        template <typename T>
        auto operator*(const double& c1, const Vector2<T>& vec1) -> Vector2<T> {
            return Vector2<T>(c1 * vec1.x, c1 * vec1.y);
        }

        template <typename T>
        auto operator*(const Vector2<T>& vec1, const double& c1) -> Vector2<T> {
            return Vector2<T>(c1 * vec1.x, c1 * vec1.y);
        }

    }  // namespace Math
}  // namespace AnimeDefendersEngine
