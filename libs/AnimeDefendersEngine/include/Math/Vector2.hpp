#pragma once

#include <cmath>
#include <iostream>

namespace AnimeDefendersEngine::Math {
    /*!
        \brief Структура, реализующая двумерный вектор.

        Реализованы стандартные операции над векторами, т.к. скалярное умножение, норма, сложение и вычитание.
    */
    template <typename T>
    struct Vector2 {
        Vector2() = default;

        explicit Vector2(T val1, T val2) : x(val1), y(val2) {}

        auto norm() const -> T;

        auto operator+(Vector2 vec) const -> Vector2;

        auto operator-(Vector2 vec) const -> Vector2;

        auto operator*(Vector2 vec) const -> T;

        auto operator*(double c1) const -> Vector2;

        T x{0.f};
        T y{0.f};
    };

    template <typename T>
    std::ostream& operator<<(std::ostream& os, Vector2<T> vec);

    template <typename T>
    auto operator*(double c1, Vector2<T> vec1) -> Vector2<T>;

    using Vector2f = Vector2<float>;

}  // namespace AnimeDefendersEngine::Math
