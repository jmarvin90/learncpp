#include <iostream>
#include "edge.h"
#include "point.h"

int main() {
    Point start(3, 3);
    Point end(9, 12);
    Edge my_edge(start, end);
    std::vector<Point> my_points {
        my_edge.intermediary_points()
    };

    return 0;
}