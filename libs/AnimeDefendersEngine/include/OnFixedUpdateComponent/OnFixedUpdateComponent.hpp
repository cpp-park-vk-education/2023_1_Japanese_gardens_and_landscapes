#pragma once

#include "BaseComponent.hpp"
#include "ComponentManager.hpp"

#include <functional>
#include <memory>

namespace AnimeDefendersEngine {

    class OnFixedUpdateComponent : public BaseComponent<OnFixedUpdateComponent> {
     public:
        OnFixedUpdateComponent(const std::string& entityId, ComponentManager& compManager, std::function<void()> onFixedUpdate);

        auto onFixedUpdate() -> void;

     private:
        std::function<void()> m_onFixedUpdate;
    };

}  // namespace AnimeDefendersEngine
