#include "Shape.hpp"

using namespace AnimeDefendersEngine::Physics;

Shape::~Shape() {}

auto Shape::getType() const -> ShapeType {
    return ShapeType::circle;
}

Circle::Circle(float radius) : radius(radius) {}

Rectangle::Rectangle(Math::Vector2<float> size) : size(size) {}
