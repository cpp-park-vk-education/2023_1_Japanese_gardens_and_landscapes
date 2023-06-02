#include "TransposeMathWrapper.hpp"

#include <GL/gl.h>
#include <iostream>

namespace AnimeDefendersEngine::Graphics {

    auto TransposeMathWrapper::applyTransposeMatrix(const Math::Transpose& transpose) const noexcept -> void {
        glPushMatrix();
        glTranslated(transpose.posCoords.x, transpose.posCoords.y, transpose.posCoords.z);
        glRotated(transpose.vecticalViewAngle, 1, 0, 0);
        glRotated(transpose.horisontalViewAngle, 0, 1, 0);
    }

    auto TransposeMathWrapper::dropLastMatrix() const noexcept -> void {
        glPopMatrix();
    }

}  // namespace AnimeDefendersEngine::Graphics
