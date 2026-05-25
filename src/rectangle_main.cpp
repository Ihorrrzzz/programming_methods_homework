#include <iostream>

#include "Figure.h"
#include "Rectangle.h"

int main() {
    Rectangle rectangle("аудиторний прямокутник", 4.0, 5.0);
    const Figure& figure = rectangle;

    figure.print();
    std::cout << "Площа: " << figure.area() << '\n';
    std::cout << "Периметр: " << figure.perimeter() << '\n';
    return 0;
}
