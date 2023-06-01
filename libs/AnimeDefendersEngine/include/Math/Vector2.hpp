#pragma once

#include <cmath>
#include <cstdint>
#include <cstring>
#include <iostream>

namespace {

    constexpr auto invSquareRootConstantFloat = 0x5F375A86;
    constexpr auto invSquareRootConstantDouble = 0x5fe6eb50c7b537a9;

    auto inverseSquareRoot(float number) -> float {
        float xhalf = 0.5f * number;
        std::uint32_t i = *reinterpret_cast<std::uint32_t*>(&number);
        i = invSquareRootConstantFloat - (i >> 1);
        number = *reinterpret_cast<float*>(&i);
        number *= 1.5f - xhalf * number * number;

        return number;
    }

    auto inverseSquareRoot(double number) -> double {
        double xhalf = number * 0.5;
        std::int64_t i = *reinterpret_cast<std::int64_t*>(&number);
        i = invSquareRootConstantDouble - (i >> 1);
        number = *reinterpret_cast<double*>(&i);
        number *= 1.5 - xhalf * number * number;
        return number;
    }
}  // namespace

namespace AnimeDefendersEngine::Math {
    /*!
        \brief Структура, реализующая двумерный вектор.

        Реализованы стандартные операции над векторами, т.к. скалярное умножение, норма, сложение и вычитание.
    */
    template <typename T>
    struct Vector2 {
        Vector2() = default;

        explicit Vector2(T val1, T val2) : x(val1), y(val2) {}

        auto operator*(Vector2<T> vec) const -> T { return this->x * vec.x + this->y * vec.y; }

        auto norm() const -> T {
            return std::sqrt((*this) * (*this));
            // return 1 / inverseSquareRoot((*this) * (*this));
        }

        auto operator+(Vector2<T> vec) const -> Vector2<T> { return Vector2{this->x + vec.x, this->y + vec.y}; }

        auto operator-(Vector2<T> vec) const -> Vector2<T> { return Vector2{this->x - vec.x, this->y - vec.y}; }

        auto operator*(T c1) const -> Vector2<T> { return Vector2{c1 * this->x, c1 * this->y}; }

        T x{};
        T y{};
    };

    template <typename T>
    std::ostream& operator<<(std::ostream& os, Vector2<T> vec) {
        os << "(" << vec.x << ", " << vec.y << ")";
        return os;
    }

    template <typename T>
    auto operator*(T c1, Vector2<T> vec1) -> Vector2<T> {
        return Vector2{c1 * vec1.x, c1 * vec1.y};
    }

    using Vector2f = Vector2<float>;
    using Vector2d = Vector2<double>;

}  // namespace AnimeDefendersEngine::Math
