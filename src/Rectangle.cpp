#include "Rectangle.h"

#include <iostream>

Rectangle::Rectangle() : Figure("прямокутник"), width(0.0), height(0.0) {}

Rectangle::Rectangle(const std::string& name, double width, double height)
    : Figure(name), width(width), height(height) {}

void Rectangle::setWidth(double newWidth) {
    width = newWidth;
}

void Rectangle::setHeight(double newHeight) {
    height = newHeight;
}

double Rectangle::getWidth() const {
    return width;
}

double Rectangle::getHeight() const {
    return height;
}

double Rectangle::area() const {
    return width * height;
}

double Rectangle::perimeter() const {
    return 2.0 * (width + height);
}

void Rectangle::print() const {
    std::cout << "Прямокутник: " << name << "; центр: (" << x << ", " << y
              << "); ширина: " << width << "; висота: " << height << '\n';
}
