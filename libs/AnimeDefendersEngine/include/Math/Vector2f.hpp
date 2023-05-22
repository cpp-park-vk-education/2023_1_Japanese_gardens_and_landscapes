#pragma once

#include <cmath>
#include <iostream>

namespace AnimeDefendersEngine {
    namespace Math {
        /*!
            \brief Структура, реализующая двумерный вектор.

            Реализованы стандартные операции над векторами, т.к. скалярное умножение, норма, сложение и вычитание.
        */
        struct Vector2f {
            explicit Vector2f(float val1 = float{}, float val2 = float{}) : x(val1), y(val2) {}
            auto norm() const -> float;
            float x;
            float y;
        };

        float inverseSquareRoot(const float n);

        std::ostream& operator<<(std::ostream& os, const Vector2f& vec);

        auto operator+(const Vector2f& vec1, const Vector2f& vec2) -> Vector2f;

        auto operator-(const Vector2f& vec1, const Vector2f& vec2) -> Vector2f;

        auto operator*(const Vector2f& vec1, const Vector2f& vec2) -> float;

        auto operator*(const float& c1, const Vector2f& vec1) -> Vector2f;

        auto operator*(const Vector2f& vec1, const float& c1) -> Vector2f;

    }  // namespace Math
}  // namespace AnimeDefendersEngine
