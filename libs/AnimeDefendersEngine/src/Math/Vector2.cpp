#include "Vector2.hpp"

#include <cstdint>
#include <cstring>

namespace {
    constexpr int invSquareRootConstant = 0x5f3759df;

    template <typename T>
    auto inverseSquareRoot(T number) -> T {
        auto xhalf = 0.5 * number;
        std::uint32_t i;
        std::memcpy(&i, &number, sizeof(i));
        i = invSquareRootConstant - (i >> 1);
        std::memcpy(&number, &i, sizeof(number));
        number *= (1.5f - xhalf * number * number);
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
        return 1 / inverseSquareRoot<T>((*this) * (*this));
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
