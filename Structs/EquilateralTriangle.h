//
// Created by jekab on 10/17/2024.
//

#ifndef EQUILATERALTRIANGLE_H
#define EQUILATERALTRIANGLE_H
#include "Triangle.h"


struct EquilateralTriangle: public Triangle {
    private:
        Line line;
    public:
        EquilateralTriangle(Line lineA, Line lineB, Line lineC);
        bool isEquilateralTriangle();
        double getArea();
        double getPerimeter();
        Line getEquilateralLine();
};



#endif //EQUILATERALTRIANGLE_H
