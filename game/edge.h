#ifndef EDGE_H
#define EDGE_H

#include "point.h"
#include <vector>

class Edge {
private:
    Point m_origin;
    Point m_termination;

public:
    Edge(const Point& origin, const Point& termination);
    friend bool operator==(Edge& e1, Edge& e2);
    const Point& get_origin() const;
    const Point& get_termination() const;
    int x_diff() const;
    int y_diff() const;
    double y_intercept() const;
    int diagonal_distance() const;
    double length() const;
    bool is_vertical() const;
    bool is_horizontal() const;
    double gradient() const;
    Point centre() const;
    bool intersects(const Edge& edge) const;
    bool is_parallel_to(const Edge& edge) const;
    std::vector<Point> intermediary_points(int n_steps=0) const;
};

int orientation(const Point& p1, const Point& p2, const Point& p3);
int interpolate(int start, int end, double step);

#endif