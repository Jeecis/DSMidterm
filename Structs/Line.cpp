//
// Created by jekab on 10/17/2024.
//

#include "Line.h"
#include <cmath>

Line::Line(Point start, Point end): start(start), end(end) {
    this->start = start;
    this->end = end;
}

Point Line::getStart() {
    return this->start;
}

Point Line::getEnd() {
    return this->end;
}

// ASked chatGPT how to calculate the lines length given 2 points lol
double Line::getLength() {
    double dx = this->end.getX() - this->start.getX();
    double dy = this->end.getY() - this->start.getY();
    return std::sqrt(dx * dx + dy * dy);
}


