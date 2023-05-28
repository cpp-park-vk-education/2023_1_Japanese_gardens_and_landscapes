#include "Vector2.hpp"

#include <cstdint>
#include <cstring>

namespace {
    constexpr auto invSquareRootConstantFloat = 0x5F375A86;
    constexpr auto invSquareRootConstantDouble = 0x5fe6eb50c7b537a9;

    auto inverseSquareRoot(float number) -> float
    {
        float xhalf = 0.5f * number;
        std::uint32_t i = *reinterpret_cast<std::uint32_t *>(&number);
        i = invSquareRootConstantFloat - (i >> 1);
        number = *reinterpret_cast<float *>(&i);
        number *= 1.5f - xhalf * number * number;

        return number;
    }

    auto inverseSquareRoot(double number) -> double
    {
        double xhalf = number * 0.5;
        std::int64_t i = *reinterpret_cast<std::int64_t *>(&number);
        i = invSquareRootConstantDouble - (i >> 1);
        number = *reinterpret_cast<double *>(&i);
        number *= 1.5 - xhalf * number * number;
        return number;
    }
}  // namespace

namespace AnimeDefendersEngine {

    template <typename T>
    auto Math::Vector2<T>::operator*(Vector2<T> vec) const -> T {
        return this->x * vec.x + this->y * vec.y;
    }

    template <typename T>
    auto Math::Vector2<T>::norm() const -> T {
        return 1 / inverseSquareRoot((*this) * (*this));
    }
    
    template <typename T>
    std::ostream& Math::operator<<(std::ostream& os, Vector2<T> vec) {
        os << "(" << vec.x << ", " << vec.y << ")";
        return os;
    }

    template <typename T>
    auto Math::Vector2<T>::operator+(Vector2<T> vec) const -> Vector2<T> {
        return Vector2{this->x + vec.x, this->y + vec.y};
    }

    template <typename T>
    auto Math::Vector2<T>::operator-(Vector2<T> vec) const -> Vector2<T> {
        return Vector2{this->x - vec.x, this->y - vec.y};
    }

    template <typename T>
    auto Math::operator*(double c1, Vector2<T> vec1) -> Vector2<T> {
        return Vector2{c1 * vec1.x, c1 * vec1.y};
    }

    template <typename T>
    auto Math::Vector2<T>::operator*(double c1) const -> Vector2<T> {
        return Vector2{c1 * this->x, c1 * this->y};
    }

}  // namespace AnimeDefendersEngine
