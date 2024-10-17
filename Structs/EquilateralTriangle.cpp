//
// Created by jekab on 10/17/2024.
//

#include "EquilateralTriangle.h"

#include <cmath>

// EquilateralTriangle::EquilateralTriangle(Line lineA, Line lineB, Line lineC)
// : Triangle(lineA, lineB, lineC), lineA(lineA), lineB(lineB), lineC(lineC) {
//
// }

Line EquilateralTriangle::getEquilateralLine() {
    return this->line;
}

bool EquilateralTriangle::isEquilateralTriangle(){
    return true;
}

double EquilateralTriangle::getPerimeter() {
    return this->line.getLength()*3;
}

double EquilateralTriangle::getArea() {
    double side =this->getEquilateralLine().getLength();
    return (std::sqrt(3) / 4) * std::pow(side, 2);
}

