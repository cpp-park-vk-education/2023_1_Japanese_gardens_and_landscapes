#include "BodyDefinition.hpp"

using namespace AnimeDefendersEngine::Physics;

BodyDefinition::BodyDefinition(size_t id, std::unique_ptr<Shape>&& shapeUPtr, BodyType bodyType, Transform transform,
                               Math::Vector2<float> velocity, size_t layers, Math::Vector2<float> force, bool isTrigger)
    : id(id),
      shapeUPtr(std::move(shapeUPtr)),
      bodyType(bodyType),
      transform(transform),
      velocity(velocity),
      layers(layers),
      force(force),
      isTrigger(isTrigger){};

BodyDefinition::BodyDefinition(BodyDefinition&& other)
    : id(other.id),
      shapeUPtr(std::move(other.shapeUPtr)),
      bodyType(other.bodyType),
      transform(other.transform),
      velocity(other.velocity),
      layers(other.layers),
      force(other.force),
      isTrigger(other.isTrigger) {}

BodyDefinition::BodyDefinition() : id(), shapeUPtr(nullptr), bodyType(), transform(), velocity(), layers(), force(), isTrigger() {}
