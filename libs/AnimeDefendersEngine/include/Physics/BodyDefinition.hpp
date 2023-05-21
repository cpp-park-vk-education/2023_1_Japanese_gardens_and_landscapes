#pragma once

#include "Shape.hpp"
#include "Vector2.hpp"

#include <memory>

namespace AnimeDefendersEngine::Physics {

    enum class BodyType {
        dynamicBody,
        staticBody
    };

    struct Transform {
        Transform(Math::Vector2f position = Math::Vector2f{}) : position(position){};
        Math::Vector2f position;
    };

    constexpr float defaultMass = 1.f;

    struct BodyDefinition {
        BodyDefinition() = default;
        BodyDefinition(std::string id, std::unique_ptr<Shape>&& shape, BodyType bodyType, Transform transform,
                       const Math::Vector2f& velocity, float mass, std::size_t layers, const Math::Vector2f& force, bool isTrigger);

        BodyDefinition(BodyDefinition&& other);
        BodyDefinition(const BodyDefinition& other) = delete;

        BodyDefinition& operator=(const BodyDefinition& other) = delete;
        BodyDefinition& operator=(BodyDefinition&& other) = delete;

        ~BodyDefinition() = default;

        std::string id{};
        BodyType bodyType{BodyType::dynamicBody};
        bool isTrigger{false};

        std::unique_ptr<Shape> shape;
        Transform transform;
        Math::Vector2f velocity;
        float mass{defaultMass};
        Math::Vector2f force;

        std::size_t layers{0};
    };

}  // namespace AnimeDefendersEngine::Physics
