#pragma ones

#include <vector>

#include "Texture.hpp"

struct Animation {
    std::vector<Texture> frames;
    int timeInterval;
};
