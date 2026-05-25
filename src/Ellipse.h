#ifndef PROGRAMMING_METHODS_ELLIPSE_H
#define PROGRAMMING_METHODS_ELLIPSE_H

#include <string>

#include "Figure.h"

class Ellipse : public Figure {
public:
    Ellipse(const std::string& name, double semiMajorAxis, double semiMinorAxis);

    double getSemiMajorAxis() const;
    double getSemiMinorAxis() const;
    double area() const override;
    double perimeter() const override;
    void print() const override;

private:
    double semiMajorAxis;
    double semiMinorAxis;
};

#endif
