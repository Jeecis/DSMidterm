//
// Created by jekab on 10/17/2024.
//

#include "Triangle.h"

#include <cmath>
#include <set>
#include <stdexcept>

struct PointComparator;
// Asked chatGPT about the set implementation but logic was written by myself
bool Triangle::isValid(Line lineA, Line lineB, Line lineC) {
    // Get all points
    Point aStart = lineA.getStart();
    Point aEnd = lineA.getEnd();
    Point bStart = lineB.getStart();
    Point bEnd = lineB.getEnd();
    Point cStart = lineC.getStart();
    Point cEnd = lineC.getEnd();

    // Check for unique points among these
    int uniqueCount = 0;

    // Helper lambda to compare two points
    auto isUnique = [](Point p1, Point p2) {
        return p1.getX() != p2.getX() || p1.getY() != p2.getY();
    };

    // Count unique points by checking against previously counted points
    if (isUnique(aStart, aEnd)) uniqueCount++;
    if (isUnique(aStart, bStart) && isUnique(aEnd, bStart)) uniqueCount++;
    if (isUnique(aStart, bEnd) && isUnique(aEnd, bEnd) && isUnique(bStart, bEnd)) uniqueCount++;
    if (isUnique(aStart, cStart) && isUnique(aEnd, cStart) && isUnique(bStart, cStart) && isUnique(bEnd, cStart)) uniqueCount++;
    if (isUnique(aStart, cEnd) && isUnique(aEnd, cEnd) && isUnique(bStart, cEnd) && isUnique(bEnd, cEnd) && isUnique(cStart, cEnd)) uniqueCount++;

    // To be a triangle, we need exactly three unique points
    return uniqueCount == 3;
}

Triangle::Triangle(Line lineA, Line lineB, Line lineC): lineA(lineA), lineB(lineB), lineC(lineC) {
    bool validCheck = isValid(lineA, lineB, lineC);
    if (validCheck) {
        throw std::invalid_argument("Invalid side lengths for a triangle");
    }

    this->lineA = lineA;
    this->lineB = lineB;
    this->lineC = lineC;
}

bool Triangle::isEquilateral() {
    double leeway1 = this->lineA.getLength() - this->lineB.getLength();
    double leeway2 = this->lineC.getLength() - this->lineB.getLength();
    double leeway3 = this->lineC.getLength() - this->lineA.getLength();

    bool check1 = (leeway1<=0.01 && leeway1>=-0.01);
    bool check2 = (leeway2<=0.01 && leeway2>=-0.01);
    bool check3 = (leeway3<=0.01 && leeway3>=-0.01);

    // considering that the length of lines can differ a bit
    // I am checking whether their leeway values instead of comparing them
    if (check1 && check2 && check3) {
        return true;
    }
    return false;
}

// Uses Heron formula to calculate the area
double Triangle::getArea() {
    double a=this->lineA.getLength();
    double b=this->lineB.getLength();
    double c=this->lineC.getLength();

    double halfPermiter = this->getPerimeter()/ 2;
    return std::sqrt(halfPermiter * (halfPermiter - a) * (halfPermiter - b) * (halfPermiter - c));
}

double Triangle::getPerimeter() {
    double lengthA = this->lineA.getLength();
    double lengthB = this->lineB.getLength();
    double lengthC = this->lineC.getLength();
    return lengthA + lengthB + lengthC;
}

Line Triangle::getLineA() {
    return this->lineA;
}

Line Triangle::getLineB() {
    return this->lineB;
}

Line Triangle::getLineC() {
    return this->lineC;
}

