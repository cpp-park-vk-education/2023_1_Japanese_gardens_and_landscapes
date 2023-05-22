#pragma once

#include "Vector2f.hpp"

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

    constexpr float defaultRadius = 1.f;

    class Circle : public Shape {
     public:
        explicit Circle(float radius = defaultRadius);
        float radius;
    };

    class Rectangle : public Shape {
     public:
        explicit Rectangle(Math::Vector2f size);
        Math::Vector2f size;
    };

}  // namespace AnimeDefendersEngine::Physics
