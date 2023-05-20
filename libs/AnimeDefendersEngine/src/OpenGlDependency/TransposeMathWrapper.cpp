#include "TransposeMathWrapper.hpp"

#include <GL/gl.h>

using namespace AnimeDefendersEngine::Graphics;

auto TransposeMathWrapper::applyTransposeMatrix(const Transpose& transpose) const -> void {
    glPushMatrix();
    glRotated(transpose.m_vecticalViewAngle, 1, 0, 0);
    glRotated(transpose.m_horisontalViewAngle, 0, 1, 0);
    glTranslated(transpose.m_posCoords[0], transpose.m_posCoords[1], transpose.m_posCoords[2]);
}

auto TransposeMathWrapper::dropLastMatrix() const -> void {
    glPopMatrix();
}
