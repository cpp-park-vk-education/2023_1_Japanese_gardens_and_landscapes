#pragma once

#include "Vector2.hpp"

namespace AnimeDefendersEngine::Physics {

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
        explicit Rectangle(Math::Vector2<float> size);
        Math::Vector2<float> size;
    };

}  // namespace AnimeDefendersEngine::Physics
