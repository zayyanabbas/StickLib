#include <iostream>
#include "Shapes.hpp"
//#include <type_traits>

int main() {
    Polygon<int, 5> poly({
        Point2D<int>(28,0),
        Point2D<int>(30, -2),
        Point2D<int>(32,-0),
        Point2D<int>(29,1),
        Point2D<int>(31,1)
    });
    for (auto& i : poly.edges) {
        std::cout << i[0] << ", " << i[1] << "\n";
    }
}