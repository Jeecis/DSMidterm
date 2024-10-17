// Čudars Jēkabs 231RDB342
#include <fstream>
#include <iostream>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stdexcept>

#include "structs/EquilateralTriangle.h"
#include "structs/Triangle.h"
#include "structs/Line.h"
#include "structs/Point.h"

std::vector<Triangle> readTXT(std::string fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return std::vector<Triangle>();
    }

    std::vector<Triangle> triangles;
    double x, y;
    std::vector<Point> points;

    while (file >> x >> y) {
        points.push_back(Point(x, y));

        // Every three points (six values) form a triangle
        if (points.size() == 6) {
            Line lineA =  Line(points[0], points[1]);
            Line lineB =  Line(points[2], points[3]);
            Line lineC =  Line(points[4], points[5]);


            try {
                Triangle triangle = Triangle(lineA, lineB, lineC);
                triangles.push_back(triangle);
            } catch (const std::exception& e) {
                std::cerr << "invalid triangle with points: "<< std::endl;

                for (unsigned int i = 0; i < points.size(); i++) {
                    std::cerr << "(" << points[i].getX() << ", " << points[i].getY() << ")" << std::endl;
                }
            }
            points.clear();  // Reset for the next triangle
        }
    }

    file.close();
    return triangles;
}

std::vector<Triangle> readCSV(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return std::vector<Triangle>();
    }

    std::vector<Triangle> triangles;
    std::string line;
    double x1, y1, x2, y2;
    std::vector<Line> lines;

    //ChatGPT provided this efficient method
    while (std::getline(file, line)) {
        std::istringstream ss(line); // turns line into string stream so its easier to read.
        char comma;  // To discard the commas during parsing

        // Try to read exactly four double values separated by commas
        if (ss >> x1 >> comma >> y1 >> comma >> x2 >> comma >> y2) {
            // Check if the input is valid and we have reached the end of the line after four values
            if (ss.eof()) {
                // Ensures no extra data after the expected four values
                Line line = Line(Point(x1, y1), Point(x2, y2));
                lines.push_back(line);
            }else {
                    continue;
            }

            // Every three lines form a triangle
            if (lines.size() == 3) {
                try {
                    Triangle triangle(lines[0], lines[1], lines[2]);
                    triangles.push_back(triangle);
                } catch (const std::exception& e) {
                    std::cerr << "Invalid triangle formed by lines:" << std::endl;
                    for (auto l : lines) {
                        std::cerr << "(" << l.getStart().getX() << ", " << l.getStart().getY() << ") - ("
                                  << l.getEnd().getX() << ", " << l.getEnd().getY() << ")" << std::endl;
                    }
                }
                lines.clear();  // Reset for the next triangle
            }
        } else {
            std::cerr << "Error parsing line: " << line << std::endl;
        }
    }

    file.close();
    return triangles;
}

Triangle largestAreaTriangle(std::vector<Triangle> triangles) {
    if (triangles.size() == 0) {
        std::cout << "Error: Empty triangle!" << std::endl;
    }
    Triangle maxTriangle = Triangle(triangles[0]);
    for (unsigned int i = 1; i < triangles.size(); i++) {
        Triangle currentTriangle = Triangle(triangles[i]);
        if (currentTriangle.getArea() > maxTriangle.getArea()) {
            maxTriangle = currentTriangle;
        }
    }
    return maxTriangle;
}

int main()
{

    std::string txt = "C:\\Users\\jekab\\CLionProjects\\midterm\\files\\points.txt";
    std::string csv = "C:\\Users\\jekab\\CLionProjects\\midterm\\files\\lines.csv";
    std::string dirtyCSV = "C:\\Users\\jekab\\CLionProjects\\midterm\\files\\dirty_lines.csv";
    std::vector<Triangle> txtTriangles =readTXT(txt);
    std::vector<Triangle> csvTriangles =readCSV(csv);
    std::vector<Triangle> dirtyTriangles =readCSV(dirtyCSV);

    Triangle maxTriangleTXT = largestAreaTriangle(txtTriangles);
    Triangle maxTriangleCSV = largestAreaTriangle(csvTriangles);
    Triangle maxTriangleDirty = largestAreaTriangle(dirtyTriangles);

    std::cout <<"Max triangle from txt file " << maxTriangleTXT.getArea() << std::endl;
    std::cout <<"Max triangle from csv file " << maxTriangleCSV.getArea() << std::endl;
    std::cout <<"Max triangle from dirty csv file " << maxTriangleDirty.getArea() << std::endl;
    return 0;
}
