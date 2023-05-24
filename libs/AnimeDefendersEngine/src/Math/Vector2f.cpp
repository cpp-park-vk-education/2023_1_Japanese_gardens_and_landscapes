#include "Vector2f.hpp"

#include <cstdint>
#include <cstring>

namespace {
    constexpr int invSquareRootConstant = 0x5f3759df;

    auto inverseSquareRoot(float number) -> float {
        auto xhalf = 0.5f * number;
        std::uint32_t i;
        std::memcpy(&i, &number, sizeof(i));
        i = invSquareRootConstant - (i >> 1);
        std::memcpy(&number, &i, sizeof(number));
        number *= (1.5f - xhalf * number * number);
        return number;
    }
}  // namespace

namespace AnimeDefendersEngine {

    auto Math::Vector2f::operator*(Vector2f vec) const -> float {
        return this->x * vec.x + this->y * vec.y;
    }

    auto Math::Vector2f::norm() const -> float {
        return 1 / inverseSquareRoot((*this) * (*this));
    }

    std::ostream& Math::operator<<(std::ostream& os, Vector2f vec) {
        os << "(" << vec.x << ", " << vec.y << ")";
        return os;
    }

    auto Math::Vector2f::operator+(Vector2f vec) const -> Vector2f {
        return Vector2f{this->x + vec.x, this->y + vec.y};
    }

    auto Math::Vector2f::operator-(Vector2f vec) const -> Vector2f {
        return Vector2f{this->x - vec.x, this->y - vec.y};
    }

    auto Math::operator*(float c1, Vector2f vec1) -> Vector2f {
        return Vector2f{c1 * vec1.x, c1 * vec1.y};
    }

    auto Math::Vector2f::operator*(float c1) const -> Vector2f {
        return Vector2f{c1 * this->x, c1 * this->y};
    }

}  // namespace AnimeDefendersEngine
