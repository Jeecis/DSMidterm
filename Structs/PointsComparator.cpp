#include <set>

#include "Point.h"

struct PointComparator {
    bool operator()(const Point& p1, const Point& p2) const {
        return (p1.getX() < p2.getX()) ||
               (p1.getX() == p2.getX() && p1.getY() < p2.getY());
    }
};

