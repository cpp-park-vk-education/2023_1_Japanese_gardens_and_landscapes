#include "Window.hpp"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>

using namespace AnimeDefendersEngine::Graphics;

auto subMain() -> int {
    int argc{};
    glutInit(&argc, nullptr);
    glutInitWindowSize(100, 100);
    int window = glutCreateWindow("123123");
    glutDestroyWindow(window);

    // const Window window;
    // window.createWindow();

    return 0;
}

auto main() -> int {
    return subMain();
}
