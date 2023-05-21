#include "Window.hpp"

#include <GL/glut.h>
#include <memory>

namespace AnimeDefendersEngine::Graphics {

    Window::Window(int windowWidth, int windowHeidth, const std::string& windowTitle)
        : m_windowWidth(windowWidth), m_windowHeidth(windowHeidth) {
        int argc{};
        glutInit(&argc, nullptr);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowSize(m_windowWidth, m_windowHeidth);

        m_windowId = glutCreateWindow(windowTitle.c_str());

        glMatrixMode(GL_PROJECTION);
        gluPerspective(120, 1., 0.1, 100.);
        glMatrixMode(GL_MODELVIEW);
    }

    Window::~Window() {
        glutDestroyWindow(m_windowId);
    }

    auto Window::updateFrame() const -> void {
        glutReshapeWindow(m_windowWidth, m_windowHeidth);
        glutSwapBuffers();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    auto Window::setWindowMouseHandler(void (*listener)(int, int, int, int)) const -> void {
        glutMouseFunc(listener);
    }

    auto Window::setWindowMotionHandler(void (*listener)(int, int)) const -> void {
        glutMotionFunc(listener);
    }

    auto Window::setWindowKeyboardHandler(void (*listener)(unsigned char, int, int)) const -> void {
        glutKeyboardFunc(listener);
    }

}  // namespace AnimeDefendersEngine::Graphics
