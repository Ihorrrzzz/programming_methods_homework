#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>

struct Point {
    double x;
    double y;
};

double distance(const Point& first, const Point& second) {
    return std::hypot(second.x - first.x, second.y - first.y);
}

double angleFromSides(double opposite, double firstAdjacent, double secondAdjacent) {
    const double numerator = firstAdjacent * firstAdjacent
        + secondAdjacent * secondAdjacent - opposite * opposite;
    const double denominator = 2.0 * firstAdjacent * secondAdjacent;
    const double cosine = std::clamp(numerator / denominator, -1.0, 1.0);
    const double pi = std::acos(-1.0);
    return std::acos(cosine) * 180.0 / pi;
}

int main() {
    Point a{};
    Point b{};
    Point c{};

    std::cout << "Введіть x та y для вершин A, B і C: ";
    if (!(std::cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y)) {
        std::cerr << "Помилка: потрібно ввести шість чисел.\n";
        return 1;
    }

    const double sideA = distance(b, c);
    const double sideB = distance(a, c);
    const double sideC = distance(a, b);
    const double doubleArea = std::abs(
        (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x));

    if (sideA == 0.0 || sideB == 0.0 || sideC == 0.0 || doubleArea < 1e-12) {
        std::cerr << "Помилка: задані точки не утворюють трикутник.\n";
        return 1;
    }

    const double angleA = angleFromSides(sideA, sideB, sideC);
    const double angleB = angleFromSides(sideB, sideA, sideC);
    const double angleC = angleFromSides(sideC, sideA, sideB);

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Сторони: a = " << sideA << ", b = " << sideB
              << ", c = " << sideC << '\n';
    std::cout << "Кути (градуси): A = " << angleA << ", B = " << angleB
              << ", C = " << angleC << '\n';
    std::cout << "Площа: " << doubleArea / 2.0 << '\n';
    return 0;
}
