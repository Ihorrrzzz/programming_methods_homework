#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

bool readVector(std::vector<double>& values, const char* name) {
    std::cout << "Введіть компоненти вектора " << name << ": ";
    for (double& value : values) {
        if (!(std::cin >> value)) {
            return false;
        }
    }
    return true;
}

int main() {
    int size = 0;
    std::cout << "Введіть розмірність векторів N: ";
    if (!(std::cin >> size) || size <= 0) {
        std::cerr << "Помилка: N має бути додатним цілим числом.\n";
        return 1;
    }

    std::vector<double> first(static_cast<std::size_t>(size));
    std::vector<double> second(static_cast<std::size_t>(size));
    if (!readVector(first, "A") || !readVector(second, "B")) {
        std::cerr << "Помилка: компоненти мають бути числами.\n";
        return 1;
    }

    double dotProduct = 0.0;
    double firstLengthSquared = 0.0;
    double secondLengthSquared = 0.0;
    for (int index = 0; index < size; ++index) {
        const auto position = static_cast<std::size_t>(index);
        dotProduct += first[position] * second[position];
        firstLengthSquared += first[position] * first[position];
        secondLengthSquared += second[position] * second[position];
    }

    std::cout << "Скалярний добуток: " << dotProduct << '\n';
    if (firstLengthSquared == 0.0 || secondLengthSquared == 0.0) {
        std::cerr << "Кут із нульовим вектором не визначений.\n";
        return 1;
    }

    const double denominator = std::sqrt(firstLengthSquared * secondLengthSquared);
    const double cosine = std::clamp(dotProduct / denominator, -1.0, 1.0);
    const double angleRadians = std::acos(cosine);
    const double angleDegrees = angleRadians * 180.0 / std::acos(-1.0);

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Кут: " << angleRadians << " радіан ("
              << angleDegrees << " градусів)\n";
    return 0;
}
