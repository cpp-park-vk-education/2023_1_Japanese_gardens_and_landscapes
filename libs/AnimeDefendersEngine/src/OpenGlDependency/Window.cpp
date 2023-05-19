#include "Window.hpp"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

using namespace AnimeDefendersEngine::Graphics;

auto Window::createWindow() -> void {
    int argc{};
    glutInit(&argc, nullptr);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    m_windowId = glutCreateWindow("Game");
}

auto Window::destroyWindow() -> void {
    glutDestroyWindow(m_windowId);
}

auto Window::updateFrame() const -> void {
    glutSwapBuffers();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

auto Window::setWindowMouseListener(void (*listener)(int, int, int, int)) const -> void {
    glutMouseFunc(listener);
}

auto Window::setWindowMotionListener(void (*listener)(int, int)) const -> void {
    glutMotionFunc(listener);
}

auto Window::setWindowKeyboardListener(void (*listener)(unsigned char, int, int)) const -> void {
    glutKeyboardFunc(listener);
}
