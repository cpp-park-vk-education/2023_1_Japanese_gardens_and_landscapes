#pragma once

#include "ITransposeMathWrapper.hpp"

namespace AnimeDefendersEngine::Graphics {

    class TransposeMathWrapper final : public ITransposeMathWrapper {
     public:
        TransposeMathWrapper() = default;

        auto applyTransposeMatrix(const Math::Transpose&) const noexcept -> void override;
        auto dropLastMatrix() const noexcept -> void override;
    };

}  // namespace AnimeDefendersEngine::Graphics
