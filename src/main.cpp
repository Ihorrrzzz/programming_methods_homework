#include <iostream>

#include "Ellipse.h"
#include "Figure.h"

int main() {
    double semiMajorAxis = 0.0;
    double semiMinorAxis = 0.0;

    std::cout << "Введіть велику та малу півосі еліпса: ";
    if (!(std::cin >> semiMajorAxis >> semiMinorAxis)
        || semiMajorAxis <= 0.0 || semiMinorAxis <= 0.0) {
        std::cerr << "Помилка: півосі мають бути додатними числами.\n";
        return 1;
    }

    Ellipse ellipse("навчальний еліпс", semiMajorAxis, semiMinorAxis);
    const Figure& figure = ellipse;

    figure.print();
    std::cout << "Площа: " << figure.area() << '\n';
    std::cout << "Периметр (наближення Рамануджана): "
              << figure.perimeter() << '\n';
    return 0;
}
