#include "Vector2.hpp"

using namespace AnimeDefendersEngine::Math;

template <typename T>
auto operator+(const Vector2<T>& vec1, const Vector2<T>& vec2) -> Vector2<T>{};
template <typename T>
auto operator-(const Vector2<T>& vec1, const Vector2<T>& vec2) -> Vector2<T>{};
template <typename T>
auto operator*(const Vector2<T>& vec1, const Vector2<T>& vec2) -> T{};
template <typename T>
auto operator*(const T& const1, const Vector2<T>& vec1) -> Vector2<T>{};
