//
// Created by jekab on 10/17/2024.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Line.h"


struct Triangle {
    private:
        Line lineA;
        Line lineB;
        Line lineC;

        bool isValid(Line lineA, Line lineB, Line lineC);
    public:
        Triangle(Line lineA, Line lineB, Line lineC);
        bool isEquilateral();
        double getPerimeter();
        double getArea();

        //Set up getters for potential use later
        Line getLineA();
        Line getLineB();
        Line getLineC();
};



#endif //TRIANGLE_H
