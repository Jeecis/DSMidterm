//
// Created by jekab on 10/17/2024.
//

#ifndef LINE_H
#define LINE_H
#include "Point.h"


struct Line {
    private:
        Point start;
        Point end;
    public:
    Line(Point start, Point end);

    double getLength();

    //Set up getters for potential use later
    Point getStart();
    Point getEnd();

};



#endif //LINE_H
