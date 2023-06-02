#include "DrawTextureWrapper.hpp"

#include <GL/glut.h>
#include <iostream>

namespace AnimeDefendersEngine::Graphics {

    auto DrawTextureWrapper::loadTexture(const Math::Matrix2d<Color>& pixelMatrix) const noexcept -> Texture {
        Texture newTexture;
        glGenTextures(1, &newTexture.textureId);
        glBindTexture(GL_TEXTURE_2D, newTexture.textureId);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, pixelMatrix.columns(), pixelMatrix.rows(), 0, GL_RGBA, GL_UNSIGNED_BYTE,
                     &*pixelMatrix.begin());

        glBindTexture(GL_TEXTURE_2D, 0);

        return newTexture;
    }

    auto DrawTextureWrapper::drawTexture(const Texture& texture) const noexcept -> void {
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_ALPHA_TEST);
        glAlphaFunc(GL_GREATER, 0.1f);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBindTexture(GL_TEXTURE_2D, texture.textureId);
        glPushMatrix();

        glColor3f(1, 1, 1);

        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);

        glVertexPointer(2, GL_FLOAT, 0, Texture::vertexCoords.data());
        glTexCoordPointer(2, GL_FLOAT, 0, Texture::textureCoords.data());
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);

        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
    }

}  // namespace AnimeDefendersEngine::Graphics
