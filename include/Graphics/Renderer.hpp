#pragma once

#include "IWindow.hpp"
#include "Scene.hpp"

class Renderer {
public:
  Renderer();
  auto renderObjects(Scene &) -> void;

private:
  IWindow &m_window;
};
