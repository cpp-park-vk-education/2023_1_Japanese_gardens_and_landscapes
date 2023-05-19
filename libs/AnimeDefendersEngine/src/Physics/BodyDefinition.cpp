#include "BodyDefinition.hpp"

using namespace AnimeDefendersEngine::Physics;

BodyDefinition::BodyDefinition(size_t id, std::unique_ptr<Shape>&& shape, BodyType bodyType, Transform transform,
                               const Math::Vector2f& velocity, size_t layers, const Math::Vector2f& force, bool isTrigger)
    : id(id),
      shape(std::move(shape)),
      bodyType(bodyType),
      transform(transform),
      velocity(velocity),
      layers(layers),
      force(force),
      isTrigger(isTrigger) {}

BodyDefinition::BodyDefinition(BodyDefinition&& other)
    : id(other.id),
      shape(std::move(other.shape)),
      bodyType(other.bodyType),
      transform(other.transform),
      velocity(other.velocity),
      layers(other.layers),
      force(other.force),
      isTrigger(other.isTrigger) {}
