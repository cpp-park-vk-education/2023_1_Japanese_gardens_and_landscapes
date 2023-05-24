#include "ColliderComponent.hpp"
#include "BaseComponent.hpp"
#include "Component.hpp"
#include "ComponentManager.hpp"
#include "RigidBodyComponent.hpp"
#include "Shape.hpp"
#include "TransformComponent.hpp"
#include "Vector2.hpp"

#include <memory>

namespace AnimeDefendersEngine {

    // ColliderComponent::ColliderComponent(const std::string& entityId, ComponentManager& compManager, Math::Vector2f size,
    //                                      TransformComponent& transfromComponent, RigidBodyComponent* rigidBodyComponent = nullptr)
    //     : BaseComponent<ColliderComponent>(entityId, compManager),
    //       size(size),
    //       rigidBodyComponent(rigidBodyComponent),
    //       transformComponent(transformComponent) {
    //     shapeType = Physics::ShapeType::rectangle;
    // }

    ColliderComponent::ColliderComponent(const std::string& entityId, ComponentManager& compManager, float radius,
                                         TransformComponent& transfromComponent, RigidBodyComponent* rigidBodyComponent = nullptr)
        : BaseComponent<ColliderComponent>(entityId, compManager),
          radius(radius),
          rigidBodyComponent(rigidBodyComponent),
          transformComponent(transformComponent) {
        shapeType = Physics::ShapeType::circle;
    }

}  // namespace AnimeDefendersEngine