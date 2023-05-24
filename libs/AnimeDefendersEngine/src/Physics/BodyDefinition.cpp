#include "BodyDefinition.hpp"

namespace AnimeDefendersEngine::Physics {

    BodyDefinition::BodyDefinition(const std::string& id, std::unique_ptr<Shape> shape, BodyType bodyType, Transform transform,
                                   const Math::Vector2f& velocity, float mass, std::size_t layers, const Math::Vector2f& force,
                                   bool isTrigger)
        : id(id),
          shape(std::move(shape)),
          bodyType(bodyType),
          transform(transform),
          velocity(velocity),
          mass(mass),
          layers(layers),
          force(force),
          isTrigger(isTrigger) {}

}  // namespace AnimeDefendersEngine::Physics
