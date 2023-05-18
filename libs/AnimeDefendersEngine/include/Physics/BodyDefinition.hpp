#pragma once

#include <memory>
#include "Shape.hpp"
#include "Vector2.hpp"

namespace AnimeDefendersEngine::Physics {

    enum class BodyType {
        dynamicBody,
        staticBody
    };

    struct Transform {
        Transform(Math::Vector2<float> position = Math::Vector2<float>()) : position(position){};
        Math::Vector2<float> position;
    };

    struct BodyDefinition {
        BodyDefinition() = default;
        BodyDefinition(size_t id, std::unique_ptr<Shape>&& shape, BodyType bodyType, Transform transform, Math::Vector2<float> velocity,
                       size_t layers, Math::Vector2<float> force, bool isTrigger);
        BodyDefinition(BodyDefinition&& other);

        BodyDefinition(const BodyDefinition& other) = delete;
        BodyDefinition& operator=(const BodyDefinition& other) = delete;
        BodyDefinition& operator=(BodyDefinition&& other) = delete;

        ~BodyDefinition() = default;

        size_t id{0};
        BodyType bodyType{BodyType::dynamicBody};
        bool isTrigger{false};

        std::unique_ptr<Shape> shape;

        Transform transform;
        Math::Vector2<float> velocity;
        Math::Vector2<float> force;

        size_t layers{0};
    };

}  // namespace AnimeDefendersEngine::Physics
