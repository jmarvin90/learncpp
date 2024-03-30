#include <iostream>

#include "edge.h"
#include "point.h"

int main() {
  Point start(3, 3);
  Point end(9, 12);
  Edge my_edge(start, end);
  std::vector<Point> my_points{my_edge.intermediary_points()};

  std::cout << "\n\n###########################################\n\n";
  for (int i = 0; i < my_points.size(); i++) {
    std::cout << my_points[i].get_x() << " " << my_points[i].get_y() << "\n";
  }

  return 0;
}