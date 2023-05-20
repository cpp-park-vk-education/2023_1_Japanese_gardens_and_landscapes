#include "DrawTextureWrapper.hpp"

#include <GL/glut.h>

using namespace AnimeDefendersEngine::Graphics;

auto DrawTextureWrapper::loadTexture(const Math::Matrix2d<Color>& imageData) const -> Texture {
    Texture newTexture;
    glGenTextures(1, &newTexture.textureId);
    glBindTexture(GL_TEXTURE_2D, newTexture.textureId);

    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imageData.columns(), imageData.rows(), 0, GL_RGBA, GL_UNSIGNED_BYTE, &*imageData.cbegin());

    glBindTexture(GL_TEXTURE_2D, 0);

    return newTexture;
}

auto DrawTextureWrapper::drawTexture(const Texture& texture) const -> void {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture.textureId);
    glPushMatrix();

    glColor3f(1, 1, 1);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glVertexPointer(2, GL_FLOAT, 0, &*Texture::vertexCoords.begin());
    glTexCoordPointer(2, GL_FLOAT, 0, &*Texture::texureCoords.begin());
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);

    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}
