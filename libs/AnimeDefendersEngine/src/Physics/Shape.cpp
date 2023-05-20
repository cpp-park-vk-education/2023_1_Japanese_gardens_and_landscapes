#include "Shape.hpp"

using namespace AnimeDefendersEngine::Physics;

Shape::~Shape() {}

auto Shape::getType() const -> ShapeType {
    return m_type;
}

Circle::Circle(float radius) : radius(radius) {
    m_type = ShapeType::circle;
}

Rectangle::Rectangle(const Math::Vector2f& size) : size(size) {
    m_type = ShapeType::rectangle;
}
