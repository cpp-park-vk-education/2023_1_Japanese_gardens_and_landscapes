#include "Shape.hpp"

using namespace AnimeDefendersEngine::PhysicsEngine;

Shape::~Shape() {}

auto Shape::getType() -> ShapeType {
    return ShapeType::circle;
}

Circle::Circle(float radius) : radius(radius) {}

Rectangle::Rectangle(Math::Vector2<float> size) : size(size) {}
