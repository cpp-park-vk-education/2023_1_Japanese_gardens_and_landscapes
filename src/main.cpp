#include "DrawTextureWrapper.hpp"
#include "FileSystem.hpp"

#include <GL/glut.h>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

using namespace AnimeDefendersEngine::Graphics;
using namespace AnimeDefendersEngine::Math;

auto subMain() -> int {
    AnimeDefendersEngine::FileSystem::FileSystem fs{"/build"};

    fs.loadItem("Test");
    auto image = fs.getImage("Test");

    int argc{};
    glutInit(&argc, nullptr);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1600, 1600);
    glClearColor(0, 0, 0, 0);

    glutCreateWindow("Gaaaaaaay");
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    // int width = 5;
    // int heigth = 5;
    // Matrix2d<Color> imageData{width, heigth};
    //
    // for (float i = 0; i < width; ++i) {
    //    for (float j = 0; j < heigth; ++j) {
    //        imageData.getElement[i][j] = {i / width * 255, j / heigth * 255, 255, 0};
    //    }
    //}

    const DrawTextureWrapper drawer;

    Texture texture = drawer.loadTexture(image.matrix);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(120, 1., 0.1, 100.);
    glMatrixMode(GL_MODELVIEW);

    for (double i = 0; i != 1000; ++i) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glLoadIdentity();
        glTranslated(0, 0, -2);
        glRotated(i, 0, 1, 0);

        glTranslated(0, .25, -1);

        drawer.drawTexture(texture);

        glutSwapBuffers();

        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }

    return 0;
}

auto main() -> int {
    return subMain();
}