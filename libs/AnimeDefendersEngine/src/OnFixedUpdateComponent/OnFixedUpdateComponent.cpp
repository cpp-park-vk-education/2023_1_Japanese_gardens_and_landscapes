#include "OnFixedUpdateComponent.hpp"

namespace AnimeDefendersEngine {

    OnFixedUpdateComponent::OnFixedUpdateComponent(const std::string& entityId, ComponentManager& compManager,
                                                   std::function<void()> onFixedUpdate)
        : BaseComponent<OnFixedUpdateComponent>(entityId, compManager), m_onFixedUpdate(onFixedUpdate){};

    auto OnFixedUpdateComponent::onFixedUpdate() -> void {
        m_onFixedUpdate();
    };

}  // namespace AnimeDefendersEngine
