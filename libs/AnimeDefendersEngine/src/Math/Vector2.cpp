#include "Vector2.hpp"

using namespace AnimeDefendersEngine::Math;

template <typename T>
auto Vector2<T>::operator+(const Vector2& vec1, const Vector2& vec2) -> Vector2& {};
template <typename T>
auto Vector2<T>::operator-(const Vector2& vec1, const Vector2& vec2) -> Vector2& {};
template <typename T>
auto Vector2<T>::operator*(const Vector2& vec1, const Vector2& vec2) -> T& {};
template <typename T>
auto Vector2<T>::operator*(const T& const1, const Vector2& vec1) -> Vector2& {};
