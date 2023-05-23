#pragma once

#include "ITransposeMathWrapper.hpp"
#include "Transpose.hpp"

namespace AnimeDefendersEngine {
    namespace Graphics {

        class TransposeMathWrapper : public ITransposeMathWrapper {
            auto initialIdentityMatrix() -> void override;
            auto applyTransposeMatrix(const Math::Transpose&) -> void override;
            auto dropLastMatrix() -> void override;
        };

    }  // namespace Graphics
}  // namespace AnimeDefendersEngine
