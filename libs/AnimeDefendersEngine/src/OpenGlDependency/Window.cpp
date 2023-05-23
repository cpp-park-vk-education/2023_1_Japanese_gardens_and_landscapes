#include "Window.hpp"

#include <GL/glut.h>

namespace AnimeDefendersEngine::Graphics {

    Window::Window(int windowWidth, int windowHeidth, const std::string& windowTitle) noexcept
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

    Window::~Window() noexcept {
        glutDestroyWindow(m_windowId);
    }

    auto Window::updateFrame() const noexcept -> void {
        glutReshapeWindow(m_windowWidth, m_windowHeidth);
        glutSwapBuffers();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    auto Window::setWindowMouseHandler(std::function<void(int, int, int, int)> handler) const noexcept -> void {
        glutMouseFunc(handler.target<void(int, int, int, int)>());
    }

    auto Window::setWindowMotionHandler(std::function<void(int, int)> handler) const noexcept -> void {
        glutMotionFunc(handler.target<void(int, int)>());
    }

    auto Window::setWindowKeyboardHandler(std::function<void(unsigned char, int, int)> handler) const noexcept -> void {
        glutKeyboardFunc(handler.target<void(unsigned char, int, int)>());
    }

}  // namespace AnimeDefendersEngine::Graphics
