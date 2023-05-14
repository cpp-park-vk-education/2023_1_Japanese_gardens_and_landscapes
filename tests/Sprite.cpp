#include "Sprite.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace AnimeDefendersEngine;

TEST(SpriteComponent, isSpriteVisibleToCameraTestVisiable) {
    Camera camera{};
    camera.setCameraTranspose({});

    Sprite sprite{};
    sprite.setTransform();
}