#include "BodyDefinition.hpp"

namespace AnimeDefendersEngine::Physics {

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

} // namespace AnimeDefendersEngine::Physics
