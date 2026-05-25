#include "Figure.h"

#include <iostream>

Figure::Figure() : name("фігура"), x(0), y(0) {}

Figure::Figure(const std::string& name) : name(name), x(0), y(0) {}

Figure::Figure(const std::string& name, int x, int y)
    : name(name), x(x), y(y) {}

void Figure::setName(const std::string& newName) {
    name = newName;
}

const std::string& Figure::getName() const {
    return name;
}

void Figure::setX(int newX) {
    x = newX;
}

void Figure::setY(int newY) {
    y = newY;
}

int Figure::getX() const {
    return x;
}

int Figure::getY() const {
    return y;
}

void Figure::print() const {
    std::cout << "Фігура: " << name << "; центр: (" << x << ", " << y << ")\n";
}
