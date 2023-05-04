#pragma once

#include <memory>

#include "Shape.hpp"
#include "Vector2.hpp"

namespace AnimeDefendersEngine {
    namespace PhysicsEngine {

        enum class BodyType {
            staticBody = 0,
            dynamicBody
        };

        class Transform {
         public:
            Math::Vector2 position;
        };

        struct BodyDefinition {
            size_t id;
            std::unique_ptr<Shape> shape;
            BodyType bodyType;
            Transform transform;
            Math::Vector2 velocity;
            size_t layers;
            Math::Vector2 force;
            bool isTrigger;
            BodyDefinition(const Shape& shape, Transform transform){};
        };
    }  // namespace PhysicsEngine
}  // namespace AnimeDefendersEngine