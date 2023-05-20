#pragma once

#include <vector>
#include "Body.hpp"
#include "Manifold.hpp"

namespace AnimeDefendersEngine::Physics {

    /**
     * @brief Класс, ответственный за распознавание коллизий, их уточнение и разрешение
     *
     * На широкой стадии (broadPhase) формируется массив пар, которые могут иметь коллизию.
     * На узкой стадии (narrowPhase) из этого списка находятся те, что действительно пересекаются.
     * Для этих пар происходит уточнение коллизий (specifyCollision), в которой определяется направление, в котором нужно будет
     * переместить объекты, и степень внедрения, которое задает величину перемещения.
     * Наконец, на стадии resolveCollision объекты перемещаются чтобы избавиться от внедрения.
     */
    class ICollisionHandler {
     public:
        virtual auto broadPhase(const std::vector<Body*>& bodies) const -> std::vector<Manifold> = 0;
        virtual auto narrowPhase(std::vector<Manifold>& contacts) const -> void = 0;
        virtual auto hasCollision(Body* bodyA, Body* bodyB) const -> bool = 0;
        virtual auto specifyCollision(Manifold& contact) const -> void = 0;
        virtual auto resolveCollision(Manifold& contact) const -> void = 0;
        virtual ~ICollisionHandler(){};
    };

    class CollisionHandler : public ICollisionHandler {
     public:
        [[nodiscard]] virtual auto broadPhase(const std::vector<Body*>& bodies) const -> std::vector<Manifold> override final;
        virtual auto narrowPhase(std::vector<Manifold>& bodies) const -> void override final;
        virtual auto hasCollision(Body* bodyA, Body* bodyB) const -> bool override final;
        virtual auto specifyCollision(Manifold& contact) const -> void override final;
        virtual auto resolveCollision(Manifold& contact) const -> void override final;
    };

}  // namespace AnimeDefendersEngine::Physics
