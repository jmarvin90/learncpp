#include "point.h"

#include <cmath>
#include <iostream>

// The constructor

Point::Point(double x, double y) : m_x{x}, m_y{y} {};

Point::Point(int x, int y)
    : m_x{static_cast<double>(x)}, m_y{static_cast<double>(y)} {};

// For adding points together
Point operator+(const Point& p1, const Point& p2) {
  return {p1.get_x() + p2.get_x(), p1.get_y() + p2.get_y()};
}

// For multiplying points
Point operator*(const Point& p1, const Point& p2) {
  return {p1.get_x() * p2.get_y(), p1.get_y() * p2.get_x()};
}

Point operator-(const Point& p1, const Point& p2) {
  return {p1.get_x() - p2.get_x(), p1.get_y() - p2.get_y()};
}

// For checking point equality
bool operator==(const Point& p1, const Point& p2) {
  return (p1.get_x() == p2.get_x() && p1.get_y() == p2.get_y());
}

int Point::get_x() const { return static_cast<int>(round(m_x)); }

int Point::get_y() const { return static_cast<int>(round(m_y)); }

double Point::distance_to(const Point& point) const {
  double x_delta{m_x - point.m_x};
  double y_delta{m_y - point.m_y};
  return std::hypot(x_delta, y_delta);
}

double Point::distance_to_origin() const { return distance_to(Point(0, 0)); }