//
// Created by jekab on 10/17/2024.
//

#ifndef POINT_H
#define POINT_H



struct Point {
private:
    double x;
    double y;
public:
    Point(double x, double y);

    //Set up getters for potential use later
    //Defined them here for easier understandability, since I am also using them in PointComparator
    double getX() const { return x; }
    double getY() const { return y; }

    bool operator<(const Point& other) const {
        // Define the comparison logic. For example:
        return (x < other.x) || (x == other.x && y < other.y);
    }

};



#endif //POINT_H
