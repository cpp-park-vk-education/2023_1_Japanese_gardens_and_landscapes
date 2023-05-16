#include "Vector2.hpp"

using namespace AnimeDefendersEngine::Math;

auto Vector2::operator+(const Vector2& vec1) -> Vector2& {
    Vector2 newVec{};
    newVec.x = vec1.x + vec2.x;
    newVec.y = vec1.y + vec2.y;
    return newVec;
};
auto Vector2::operator-(const Vector2& vec1) -> Vector2& {
    Vector2 newVec{};
    newVec.x = vec1.x - vec2.x;
    newVec.y = vec1.y - vec2.y;
    return newVec;
};
auto Vector2::operator*(const Vector2& vec1) -> T& {
    T scalar{};
    scalar = vec1.x * vec1.x + vec2.y * vec2.y;
    return scalar;
};
auto Vector2::operator*(const T& const1) -> Vector2& {};
