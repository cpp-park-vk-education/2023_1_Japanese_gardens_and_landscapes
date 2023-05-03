#pragma once

#include "IWindow.hpp"

class Window : public IWindow {
public:
  auto createWindow() -> void override;
  auto destroyWindow() -> void override;
  auto setWindowListener() -> void override;
  auto updateFrame() -> void override;
};
