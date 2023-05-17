#pragma once

#include <memory>

#include "Shape.hpp"
#include "Vector2.hpp"

namespace AnimeDefendersEngine {
    namespace Physics {

        enum class BodyType {
            staticBody,
            dynamicBody
        };

        struct Transform {
            Math::Vector2<float> position;
            Transform(Math::Vector2<float> position = Math::Vector2<float>()) : position(position){};
        };

        struct BodyDefinition {
            size_t id;
            std::unique_ptr<Shape> shapeUPtr;
            BodyType bodyType;
            Transform transform;
            Math::Vector2<float> velocity;
            size_t layers;
            Math::Vector2<float> force;
            bool isTrigger;
            BodyDefinition(size_t id, std::unique_ptr<Shape>&& shapeUPtr, BodyType bodyType, Transform transform,
                           Math::Vector2<float> velocity, size_t layers, Math::Vector2<float> force, bool isTrigger);
            BodyDefinition(BodyDefinition&& other);
            BodyDefinition();
        };

    }  // namespace Physics
}  // namespace AnimeDefendersEngine
