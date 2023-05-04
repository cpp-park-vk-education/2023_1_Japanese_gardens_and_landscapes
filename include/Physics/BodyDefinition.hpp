#pragma once

#include <memory>

#include "Shape.hpp"

namespace AnimeDefendersEngine {
    namespace PhysicsEngine {

        using Layers = size_t;
        using ShapeUPtr = std::unique_ptr<Shape>;

        enum class BodyType {
            staticBody = 0,
            dynamicBody
        };

        class Transform {
         public:
            // Vector2d position;
        };

        struct BodyDefinition {
            size_t ID;
            ShapeUPtr shape;
            BodyType bodyType;
            Transform transform;
            // Vector2d velocity;
            Layers layers;
            // Vector2d force;
            bool isTrigger;
            BodyDefinition(const Shape& shape, Transform transform){};
        };
    }  // namespace PhysicsEngine
}  // namespace AnimeDefendersEngine