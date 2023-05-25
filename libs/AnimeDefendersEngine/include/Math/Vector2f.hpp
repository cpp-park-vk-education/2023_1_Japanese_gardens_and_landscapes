#pragma once

#include <cmath>
#include <iostream>

namespace AnimeDefendersEngine::Math {
    /*!
        \brief Структура, реализующая двумерный вектор.

        Реализованы стандартные операции над векторами, т.к. скалярное умножение, норма, сложение и вычитание.
    */
    struct Vector2f {
        Vector2f() = default;

        explicit Vector2f(float val1, float val2) : x(val1), y(val2) {}

        auto norm() const -> float;

        auto operator+(Vector2f vec) const -> Vector2f;

        auto operator-(Vector2f vec) const -> Vector2f;

        auto operator*(Vector2f vec) const -> float;

        auto operator*(float c1) const -> Vector2f;

        float x{0.f};
        float y{0.f};
    };

    std::ostream& operator<<(std::ostream& os, Vector2f vec);

    auto operator*(float c1, Vector2f vec1) -> Vector2f;

}  // namespace AnimeDefendersEngine::Math
