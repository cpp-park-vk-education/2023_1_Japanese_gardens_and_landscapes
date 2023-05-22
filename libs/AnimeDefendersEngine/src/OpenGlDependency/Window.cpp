#include "Window.hpp"

#include <GL/glut.h>
#include <memory>

namespace AnimeDefendersEngine::Graphics {

    Window::Window(int windowWidth, int windowHeidth, const std::string& windowTitle)
        : m_windowWidth(windowWidth), m_windowHeidth(windowHeidth) noexcept {
        int argc{};
        glutInit(&argc, nullptr);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowSize(m_windowWidth, m_windowHeidth);

        m_windowId = glutCreateWindow(windowTitle.c_str());

        glMatrixMode(GL_PROJECTION);
        gluPerspective(120, 1., 0.1, 100.);
        glMatrixMode(GL_MODELVIEW);
    }

    Window::~Window() noexcept {
        glutDestroyWindow(m_windowId);
    }

    auto Window::updateFrame() const noexcept -> void {
        glutReshapeWindow(m_windowWidth, m_windowHeidth);
        glutSwapBuffers();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    auto Window::setWindowMouseHandler(void (*handler)(int, int, int, int)) const noexcept -> void {
        glutMouseFunc(handler);
    }

    auto Window::setWindowMotionHandler(void (*handler)(int, int)) const noexcept -> void {
        glutMotionFunc(handler);
    }

    auto Window::setWindowKeyboardHandler(void (*handler)(unsigned char, int, int)) const noexcept -> void {
        glutKeyboardFunc(handler);
    }

}  // namespace AnimeDefendersEngine::Graphics
