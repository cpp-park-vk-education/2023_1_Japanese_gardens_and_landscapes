#pragma once

class IWindow {
public:
  virtual auto createWindow() -> void = 0;
  virtual auto destroyWindow() -> void = 0;
  virtual auto setWindowListener() -> void = 0;
  virtual auto updateFrame() -> void = 0;
};
