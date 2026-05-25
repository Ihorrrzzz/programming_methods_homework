#ifndef PROGRAMMING_METHODS_RECTANGLE_H
#define PROGRAMMING_METHODS_RECTANGLE_H

#include <string>

#include "Figure.h"

class Rectangle : public Figure {
public:
    Rectangle();
    Rectangle(const std::string& name, double width, double height);

    void setWidth(double width);
    void setHeight(double height);

    double getWidth() const;
    double getHeight() const;
    double area() const override;
    double perimeter() const override;
    void print() const override;

private:
    double width;
    double height;
};

#endif
