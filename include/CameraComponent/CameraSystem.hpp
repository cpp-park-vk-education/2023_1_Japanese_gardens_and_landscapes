#pragma ones

#include "Camera.hpp"
#include "System.hpp"

class CameraSystem : public System {
public:
  CameraSystem() = 0;

  static auto determineNewCameraTranspose(Camera *) -> void;
  static auto applyCameraView(Camera *) -> void;
};
