#pragma once

#include "Vector2.hpp"

namespace AnimeDefendersEngine::Physics {

    /// \details Числовые значения этого enum используются обработчиком коллизий CollisionHandler, для определения конкретной функции,
    /// обрабатывающей конкретные формы
    enum class ShapeType : int {
        circle = 0,
        rectangle
    };

    class Shape {
     public:
        virtual ~Shape();
        auto getType() const -> ShapeType;
        static constexpr int shapeCount = 2;

     protected:
        ShapeType m_type;
    };

    class Circle : public Shape {
     public:
        explicit Circle(float radius);
        float radius;
    };

    class Rectangle : public Shape {
     public:
        explicit Rectangle(const Math::Vector2f& size);
        Math::Vector2f size;
    };

}  // namespace AnimeDefendersEngine::Physics
