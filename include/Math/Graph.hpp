#pragma once
#include "Component.hpp"
#include "Matrix.hpp"

#include <vector>

namespace AnimeDefendersEngine {
    class Graph {
     public:
        struct Point {
            int x;
            int y;
        };

     public:
        explicit Graph(const std::vector<Component*>& components, int resolution, std::pair<Point, Point> coordinatsRange);
        auto fidnPath(Point from, Point where) -> std::vector<Point>;

     private:
        Math::Matrix2d<int> m_matrix;
    };

}  // namespace AnimeDefendersEngine