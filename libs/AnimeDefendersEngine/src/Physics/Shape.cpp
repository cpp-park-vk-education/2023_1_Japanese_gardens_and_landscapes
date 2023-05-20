#include "Shape.hpp"

using namespace AnimeDefendersEngine::Physics;

auto Shape::getType() const -> ShapeType {
    return m_type;
}

Circle::Circle(float radius) : radius(radius) {
    m_type = ShapeType::circle;
}

Rectangle::Rectangle(Math::Vector2f size) : size(std::move(size)) {
    m_type = ShapeType::rectangle;
}
