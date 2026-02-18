#include <cmath>
#include <iostream>

int main() {
    double x = 0.0;
    double y = 0.0;

    std::cout << "Введіть координати x та y: ";
    if (!(std::cin >> x >> y)) {
        std::cerr << "Помилка: координати мають бути числами.\n";
        return 1;
    }

    const double radius = std::sqrt(x * x + y * y);
    const double angle = std::atan2(y, x); // atan2 правильно визначає чверть кута.

    std::cout << "Радіус: " << radius << '\n';
    std::cout << "Полярний кут (радіани): " << angle << '\n';
    return 0;
}
