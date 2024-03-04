#include <iostream>
#include <cmath>

struct Coordinate{
    int x_pos;
    int y_pos;
};

struct Edge{
    Coordinate origin;
    Coordinate termination;
};

float length(const Edge &edge) {
    int x_diff = {edge.origin.x_pos - edge.termination.x_pos};
    int y_diff = {edge.origin.y_pos - edge.termination.y_pos};
    return std::hypot(x_diff, y_diff);
}

int main() {

    Coordinate x_pos = {0, 5};
    Coordinate y_pos = {5, 0};

    Edge edge = {x_pos, y_pos};
    
    std::cout << length(edge) << "\n";
}