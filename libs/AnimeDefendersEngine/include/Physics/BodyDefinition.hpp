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
        Transform(Math::Vector2f position = Math::Vector2f()) : position(position){};
        Math::Vector2f position;
    };

    struct BodyDefinition {
        BodyDefinition() = default;
        BodyDefinition(size_t id, std::unique_ptr<Shape>&& shape, BodyType bodyType, Transform transform, Math::Vector2f velocity,
                       size_t layers, Math::Vector2f force, bool isTrigger);
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
        Math::Vector2f velocity;
        Math::Vector2f force;

        size_t layers{0};
    };

}  // namespace AnimeDefendersEngine::Physics
