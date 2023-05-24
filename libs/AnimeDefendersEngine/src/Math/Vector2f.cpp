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

    auto Math::Vector2f::norm() const -> float {
        return 1 / inverseSquareRoot((*this) * (*this));
    }

    std::ostream& Math::operator<<(std::ostream& os, Vector2f vec) {
        os << "(" << vec.x << ", " << vec.y << ")";
        return os;
    }

    auto Math::operator+(Vector2f vec1, Vector2f vec2) -> Vector2f {
        return Vector2f{vec1.x + vec2.x, vec1.y + vec2.y};
    }

    auto Math::operator-(Vector2f vec1, Vector2f vec2) -> Vector2f {
        return Vector2f{vec1.x - vec2.x, vec1.y - vec2.y};
    }

    auto Math::operator*(Vector2f vec1, Vector2f vec2) -> float {
        return vec1.x * vec2.x + vec1.y * vec2.y;
    }

    auto Math::operator*(float c1, Vector2f vec1) -> Vector2f {
        return Vector2f{c1 * vec1.x, c1 * vec1.y};
    }

    auto Math::operator*(Vector2f vec1, float c1) -> Vector2f {
        return Vector2f{c1 * vec1.x, c1 * vec1.y};
    }

}  // namespace AnimeDefendersEngine
