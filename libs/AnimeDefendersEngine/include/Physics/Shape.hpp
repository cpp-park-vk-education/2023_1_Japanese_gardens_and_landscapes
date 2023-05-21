#pragma once

#include "Vector2.hpp"

namespace AnimeDefendersEngine::Physics {

    /// \details Числовые значения этого enum используются обработчиком коллизий CollisionHandler, для определения конкретной функции,
    /// обрабатывающей конкретные формы
    enum class ShapeType : int {
        circle = 0,
        rectangle
    };

    /// \details Статическая переменная в этом классе используется обработчиком коллизий (это размер массива функций обработки)
    class Shape {
     public:
        virtual ~Shape() = default;
        auto getType() const -> ShapeType;

     public:
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
        explicit Rectangle(Math::Vector2f size);
        Math::Vector2f size;
    };

}  // namespace AnimeDefendersEngine::Physics
