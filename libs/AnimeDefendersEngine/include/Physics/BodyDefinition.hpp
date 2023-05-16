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
            Math::Vector2<float> position;
        };

        struct BodyDefinition {
            size_t id;
            std::unique_ptr<Shape> shape;
            BodyType bodyType;
            Transform transform;
            Math::Vector2<float> velocity;
            size_t layers;
            Math::Vector2<float> force;
            bool isTrigger;
            BodyDefinition(const Shape& shape, Transform transform);
        };

    }  // namespace PhysicsEngine
}  // namespace AnimeDefendersEngine
