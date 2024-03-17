#ifndef POINT_H
#define POINT_H

class Point {
private:
    // The coordinates
    int m_x {};
    int m_y {};

public:
    // Declare public member functions
    Point(int x, int y);
    friend Point operator+(const Point& p1, const Point& p2);
    friend Point operator*(const Point& p1, const Point& p2);
    friend Point operator-(const Point& p1, const Point& p2);
    friend bool operator==(const Point& p1, const Point& p2);
    int get_x() const;
    int get_y() const;
    double distance_to(const Point& point) const;
    double distance_to_origin() const;
};

#endif
