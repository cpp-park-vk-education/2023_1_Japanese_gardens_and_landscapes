#include "TransposeMathWrapper.hpp"

#include <GL/gl.h>

using namespace AnimeDefendersEngine::Graphics;

auto TransposeMathWrapper::applyTransposeMatrix(const Transpose& transpose) const -> void {
    glPushMatrix();
    glRotated(transpose.vecticalViewAngle, 1, 0, 0);
    glRotated(transpose.horisontalViewAngle, 0, 1, 0);
    glTranslated(transpose.posCoords.x, transpose.posCoords.y, transpose.posCoords.z);
}

auto TransposeMathWrapper::dropLastMatrix() const -> void {
    glPopMatrix();
}
