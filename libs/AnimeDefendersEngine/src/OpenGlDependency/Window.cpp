#include "Window.hpp"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

using namespace AnimeDefendersEngine::Graphics;

auto Window::createWindow() const -> void {
    // int* argc{};
    // char* argv{};
    // glutInit(argc, &argv);
}

auto Window::destroyWindow() const -> void {}

auto Window::setWindowListener(std::function<void(int, int, int)>) const -> void {}

auto Window::updateFrame() const -> void {}
