#include <bits/stdc++.h>
#include "Vector.hpp"

template<typename T>
struct AABB {
    Point2D<T> min, max;
    AABB(Point2D<T> min, Point2D<T> max) : min(min), max(max) {}
};

template<typename T, int vert_count>
struct ConvexPolygon {
    std::array<Vector<T,2>, vert_count> edges;
    Point2D coords;
    
    Polygon(std::array<Point2D<T>,vert_count> vertices) {
        coords = edges[0];
        edges[0] = {vertices[0].x-vertices[vert_count-1].x,vertices[0].y-vertices[vert_count-1].y};
        for (int i = 0; i < vert_count-1; ++i) {
            edges[i+1] = {vertices[i+1].x-vertices[i].x, vertices[i+1].y-vertices[i].y};
        }
    }
    
    AABB construct_aabb() {
        AABB ret;
        for (auto& i : edges) {
            
        }
    }
};