#pragma once

#include <unordered_set>
#include <vector>

namespace AnimeDefendersEngine::Physics {

    class Body;
    struct Manifold;

}  // namespace AnimeDefendersEngine::Physics

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
        virtual auto broadPhase(const std::vector<Body*>& bodies) const -> std::unordered_set<Manifold> = 0;
        virtual auto narrowPhase(std::unordered_set<Manifold>& contacts) const -> void = 0;
        virtual auto hasCollision(Body* bodyA, Body* bodyB) const -> bool = 0;
        virtual auto specifyCollision(Manifold& contact) const -> void = 0;
        virtual auto resolveCollision(Manifold& contact) const -> void = 0;
        virtual ~ICollisionHandler() = default;
    };

}  // namespace AnimeDefendersEngine::Physics
