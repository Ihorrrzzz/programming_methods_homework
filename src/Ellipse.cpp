#include "Ellipse.h"

#include <cmath>
#include <iostream>

Ellipse::Ellipse(const std::string& name, double semiMajorAxis, double semiMinorAxis)
    : Figure(name), semiMajorAxis(semiMajorAxis), semiMinorAxis(semiMinorAxis) {}

double Ellipse::getSemiMajorAxis() const {
    return semiMajorAxis;
}

double Ellipse::getSemiMinorAxis() const {
    return semiMinorAxis;
}

double Ellipse::area() const {
    return std::acos(-1.0) * semiMajorAxis * semiMinorAxis;
}

double Ellipse::perimeter() const {
    const double sum = semiMajorAxis + semiMinorAxis;
    const double difference = semiMajorAxis - semiMinorAxis;
    const double h = difference * difference / (sum * sum);

    // Друге наближення Рамануджана дає просту й достатньо точну оцінку периметра.
    return std::acos(-1.0) * sum
        * (1.0 + 3.0 * h / (10.0 + std::sqrt(4.0 - 3.0 * h)));
}

void Ellipse::print() const {
    std::cout << "Еліпс: " << name << "; центр: (" << x << ", " << y
              << "); півосі: " << semiMajorAxis << " і " << semiMinorAxis << '\n';
}
