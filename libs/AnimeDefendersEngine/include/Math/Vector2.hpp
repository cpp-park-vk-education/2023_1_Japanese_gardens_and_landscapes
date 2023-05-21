#pragma once

#include <cmath>
#include <iostream>

namespace AnimeDefendersEngine {
    namespace Math {
        /*!
            \brief Шаблонная структура, реализующая двумерный вектор.

            Реализованы стандартные операции над векторами, т.к. скалярное умножение, норма, сложение и вычитание.
        */
        template <typename T>
        struct Vector2 {
            explicit Vector2(T val1 = T{}, T val2 = T{}) : x(val1), y(val2) {}
            auto norm() -> T { return sqrt((*this) * (*this)); }
            T x;
            T y;
        };

        template <typename T>
        std::ostream& operator<<(std::ostream& os, const Vector2<T>& vec) {
            os << "(" << vec.x << ", " << vec.y << ")";
            return os;
        }

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
