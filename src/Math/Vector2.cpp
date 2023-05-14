#include "Vector2.hpp"

using namespace AnimeDefendersEngine::Math;

template <typename T>
Vector2::Vector2(T val1 = T{}, T val2 = T{}){};

template <typename T>
auto Vector2::operator[](std::size_t i) -> T& {};