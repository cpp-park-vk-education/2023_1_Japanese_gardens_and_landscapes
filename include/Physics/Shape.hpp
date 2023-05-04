#pragma once

#include "Vector2.hpp"

namespace AnimeDefendersEngine {
    namespace PhysicsEngine {

        enum class ShapeType {
            circle = 0,
            rectangle
        };

        class Shape {
         public:
            virtual ~Shape();
            auto getType() -> ShapeType const;

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
    }  // namespace PhysicsEngine
}  // namespace AnimeDefendersEngine