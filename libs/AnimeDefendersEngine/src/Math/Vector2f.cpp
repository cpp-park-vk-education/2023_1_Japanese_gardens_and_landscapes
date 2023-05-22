#include "Vector2f.hpp"

auto AnimeDefendersEngine::Math::inverseSquareRoot(float number) -> float {
    const float threeHalves = 1.5;
    float y = number;
    long i = *(long*)&y;
    i = 0x5f3759df - (i >> 1);
    y = *(float*)&i;
    y = y * (threeHalves - (number * 0.5 * y * y));
    return y;
}

auto AnimeDefendersEngine::Math::Vector2f::norm() -> float {
    return 1 / inverseSquareRoot((*this) * (*this));
}

std::ostream& AnimeDefendersEngine::Math::operator<<(std::ostream& os, const Vector2f& vec) {
    os << "(" << vec.x << ", " << vec.y << ")";
    return os;
}

auto AnimeDefendersEngine::Math::operator+(const Vector2f& vec1, const Vector2f& vec2) -> Vector2f {
    return Vector2f{vec1.x + vec2.x, vec1.y + vec2.y};
}

auto AnimeDefendersEngine::Math::operator-(const Vector2f& vec1, const Vector2f& vec2) -> Vector2f {
    return Vector2f{vec1.x - vec2.x, vec1.y - vec2.y};
}

auto AnimeDefendersEngine::Math::operator*(const Vector2f& vec1, const Vector2f& vec2) -> float {
    return vec1.x * vec2.x + vec1.y * vec2.y;
}

auto AnimeDefendersEngine::Math::operator*(const float& c1, const Vector2f& vec1) -> Vector2f {
    return Vector2f{c1 * vec1.x, c1 * vec1.y};
}

auto AnimeDefendersEngine::Math::operator*(const Vector2f& vec1, const float& c1) -> Vector2f {
    return Vector2f{c1 * vec1.x, c1 * vec1.y};
}