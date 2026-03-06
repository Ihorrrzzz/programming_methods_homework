#include <cmath>
#include <iostream>

int main() {
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;

    std::cout << "Введіть коефіцієнти a, b і c: ";
    if (!(std::cin >> a >> b >> c)) {
        std::cerr << "Помилка: коефіцієнти мають бути числами.\n";
        return 1;
    }

    if (a == 0.0) {
        if (b != 0.0) {
            std::cout << "Лінійне рівняння. x = " << -c / b << '\n';
        } else if (c == 0.0) {
            std::cout << "Рівняння має нескінченно багато розв'язків.\n";
        } else {
            std::cout << "Рівняння не має розв'язків.\n";
        }
        return 0;
    }

    const double discriminant = b * b - 4.0 * a * c;
    std::cout << "Дискримінант: " << discriminant << '\n';

    if (discriminant > 0.0) {
        const double root = std::sqrt(discriminant);
        const double x1 = (-b + root) / (2.0 * a);
        const double x2 = (-b - root) / (2.0 * a);
        std::cout << "x1 = " << x1 << "\nx2 = " << x2 << '\n';
    } else if (discriminant == 0.0) {
        const double x = -b / (2.0 * a);
        std::cout << "x1 = x2 = " << x << '\n';
    } else {
        std::cout << "Дійсних коренів немає.\n";
    }

    return 0;
}
