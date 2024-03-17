#include "edge.h"
#include <cmath>

Edge::Edge(const Point& origin, const Point& termination)
    : m_origin {origin}
    , m_termination {termination} 
    {};

const Point& Edge::get_origin() const {
    return m_origin;
}

const Point& Edge::get_termination() const {
    return m_termination;
}

bool operator==(Edge& e1, Edge& e2) {
    return (
        (
            e1.m_origin == e2.m_origin &&
            e1.m_termination == e2.m_termination
        ) |
        (
            e1.m_origin == e2.m_termination &&
            e1.m_termination == e2.m_origin
        )
    );
}

int Edge::x_diff() const {
    return (m_origin.get_x() - m_termination.get_x());
}

int Edge::y_diff() const {
    return (m_origin.get_y() - m_termination.get_y());
}

bool Edge::is_vertical() const {
    return (m_origin.get_y() == m_termination.get_y());
}

bool Edge::is_horizontal() const {
    return (m_origin.get_x() == m_termination.get_x());
}

double Edge::gradient() const {
    if (is_vertical()) {
        return 1;
    }

    if (is_horizontal()) {
        return 0;
    }

    return y_diff() / x_diff();
}

double Edge::y_intercept() const {
    return (
        m_origin.get_y() - (
            gradient() * m_origin.get_x()
        )
    );
}

double Edge::length() const {
    return m_origin.distance_to(m_termination);
}

int Edge::diagonal_distance() const {
    return std::max(std::abs(x_diff()), abs(y_diff()));
}

bool Edge::intersects(const Edge& edge) const {
    int acd {orientation(m_origin, edge.m_origin, edge.m_termination)};
    int bcd {orientation(m_termination, edge.m_origin, edge.m_termination)};
    int abc {orientation(m_origin, m_termination, edge.m_origin)};
    int abd {orientation(m_origin, m_termination, edge.m_termination)};

    return (acd != bcd && abc != abd);
}

Point Edge::centre() const {
    int mid_x {(x_diff() / 2) + m_origin.get_x()};
    int mid_y {(y_diff() / 2) + m_origin.get_y()};
    return Point(mid_x, mid_y);
}

bool Edge::is_parallel_to(const Edge& edge) const {
    if (is_horizontal() && edge.is_horizontal()) {
        return true;
    }

    if (is_vertical() && edge.is_vertical()) {
        return true;
    }

    return gradient() == edge.gradient();
}

std::vector<Point> Edge::intermediary_points(int n_steps) const {
    std::vector<Point> points{m_origin, m_termination};
    if (n_steps==0) {
        n_steps = diagonal_distance();
    }

    for (float i=1.; i<=n_steps; i++) {
        double t {i / n_steps};
        double x {std::lerp(m_origin.get_x(), m_termination.get_x(), t)};
        double y {std::lerp(m_origin.get_y(), m_termination.get_y(), t)};
        points.insert(points.end() -1, Point(x, y));
    }

    return points;
}

int orientation(const Point& p1, const Point& p2, const Point& p3) {
    Edge edge_1(p2, p1);
    Edge edge_2(p3, p2);

    double val = (
        (edge_1.y_diff() * edge_2.x_diff()) - 
        (edge_1.x_diff() * edge_2.y_diff())
    );

    if (val > 1) {
        return 1;
    }

    if (val < 0) {
        return -1;
    }

    return 0;
}