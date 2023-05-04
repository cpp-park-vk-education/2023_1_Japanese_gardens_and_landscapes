#pragma once

#include "Vector2.hpp"

namespace AnimeDefendersEngine {
    namespace PhysicsEngine {

        class Shape {
         public:
            enum class Type {
                circle = 0,
                rectangle
            };
            virtual ~Shape(){};
            Type getType() const {};

         protected:
            Type m_type;
        };

        class Circle : public Shape {
         public:
            Circle(float radius) : radius(radius) { m_type = Type::circle; };
            float radius;
        };

        class Rectangle : public Shape {
         public:
            Rectangle(Math::Vector2 size) : size(size) { m_type = Type::rectangle; };
            Math::Vector2 size;
        };
    }  // namespace PhysicsEngine
}  // namespace AnimeDefendersEngine