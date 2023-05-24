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
            explicit Vector2f(float val1 = 0.f, float val2 = 0.f) : x(val1), y(val2) {}
            auto norm() const -> float;
            float x;
            float y;
        };

        std::ostream& operator<<(std::ostream& os, Vector2f vec);

        auto operator+(Vector2f vec1, Vector2f vec2) -> Vector2f;

        auto operator-(Vector2f vec1, Vector2f vec2) -> Vector2f;

        auto operator*(Vector2f vec1, Vector2f vec2) -> float;

        auto operator*(const float& c1, Vector2f vec1) -> Vector2f;

        auto operator*(Vector2f vec1, const float& c1) -> Vector2f;

    }  // namespace Math
}  // namespace AnimeDefendersEngine
