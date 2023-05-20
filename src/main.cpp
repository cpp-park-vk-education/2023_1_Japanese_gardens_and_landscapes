#define STB_IMAGE_IMPLEMENTATION

#include "DrawTextureWrapper.hpp"
#include "FileSystem.hpp"

#include <GL/glut.h>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

using namespace AnimeDefendersEngine::Graphics;

using AnimeDefendersEngine::Math::Matrix2d;

using namespace AnimeDefendersEngine::Graphics;

auto operator<<(std::ostream& stream, const Color& color) -> std::ostream& {
    stream << "{r:" << static_cast<int>(color.red) << ", g:" << static_cast<int>(color.green) << ", b:" << static_cast<int>(color.blue)
           << "}";
    return stream;
}

auto subMain() -> int {
    AnimeDefendersEngine::FileSystem::FileSystem fs{"/build"};

    fs.loadItem("Test");
    auto image = fs.getImage("Test");

    int argc{};
    glutInit(&argc, nullptr);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glClearColor(0, 0, 0, 0);

    glutCreateWindow("Gaaaaaaay");
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    std::size_t width = 800;
    std::size_t height = 800;
    Matrix2d<Color> imageData{width, height};

    for (float i = 0; i < width; ++i) {
        for (float j = 0; j < height; ++j) {
            imageData.getElement(i, j) =
                Color{static_cast<unsigned char>((i / width) * 255), static_cast<unsigned char>((j / height) * 255), 140, 1};
        }
    }

    const DrawTextureWrapper drawer;

    Texture texture = drawer.loadTexture(image.matrix);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(120, 1., 0.1, 100.);
    glMatrixMode(GL_MODELVIEW);

    for (double i = 0; i < 1000; ++i) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glLoadIdentity();
        glTranslated(0, 0, -2);
        glRotated(i, 0, 1, 0);

        glTranslated(0, .25, -1);

        drawer.drawTexture(texture);

        glutSwapBuffers();

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    return 0;
}

auto anotherSubMain() -> int {
    std::vector<Color> colors{
        {100, 110, 120, 0},
        {110, 120, 130, 0},
        {120, 130, 140, 0},
        {130, 140, 150, 0}
    };
    Matrix2d<Color> sample{2, 2, colors};

    auto pointer = reinterpret_cast<unsigned char*>(&*sample.begin());

    for (int i = 0; i < 16; i++) {
        std::cout << static_cast<int>(pointer[i]) << ' ';
    }
    std::cout << "\n";
    return 0;
}

auto main() -> int {
    return subMain();  // anotherSubMain();
}