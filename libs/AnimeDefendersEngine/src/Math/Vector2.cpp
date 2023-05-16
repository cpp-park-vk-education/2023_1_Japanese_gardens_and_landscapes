#include "Vector2.hpp"

using namespace AnimeDefendersEngine::Math;

template <typename T>
Vector2<T>::Vector2(T, T) {}

template <typename T>
auto Vector2<T>::operator[](std::size_t i) -> T& {}
