#pragma once

#include "ITransposeMathWrapper.hpp"
#include "Transform.hpp"

namespace AnimeDefendersEngine {
    namespace Graphics {

        class TransposeMathWrapper : public ITransposeMathWrapper {
            auto initialIdentityMatrix() -> void override;
            auto applyTransposeMatrix(const Transform&) -> void override;
            auto dropLastMatrix() -> void override;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
