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

    auto Window::setMouseClickHandler(mouseClickHandler handler) const noexcept -> void {
        glutMouseFunc(handler.target<void(int, int, int, int)>());
    }

    auto Window::setActiveMouseMotionHandler(mouseMotionHandler handler) const noexcept -> void {
        glutMotionFunc(handler.target<void(int, int)>());
    }

    auto Window::setPassiveMouseMotionHandler(mouseMotionHandler handler) const noexcept -> void {
        glutMotionFunc(handler.target<void(int, int)>());
    }

    auto Window::setKeyPressHandler(keyPressHandler handler) const noexcept -> void {
        glutKeyboardFunc(handler.target<void(unsigned char, int, int)>());
    }

    auto Window::isShiftPressed() const noexcept -> bool {
        return glutGetModifiers() & GLUT_ACTIVE_SHIFT;
    }

    auto Window::isCtrlPressed() const noexcept -> bool {
        return glutGetModifiers() & GLUT_ACTIVE_CTRL;
    }

    auto Window::isAltPressed() const noexcept -> bool {
        return glutGetModifiers() & GLUT_ACTIVE_ALT;
    }

}  // namespace AnimeDefendersEngine::Graphics
