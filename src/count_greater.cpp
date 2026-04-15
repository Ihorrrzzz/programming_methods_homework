#include <iostream>
#include <vector>

int main() {
    int size = 0;
    std::cout << "Введіть кількість елементів N: ";
    if (!(std::cin >> size) || size <= 0) {
        std::cerr << "Помилка: N має бути додатним цілим числом.\n";
        return 1;
    }

    std::vector<double> values(static_cast<std::size_t>(size));
    std::cout << "Введіть елементи масиву: ";
    for (double& value : values) {
        if (!(std::cin >> value)) {
            std::cerr << "Помилка: елементи мають бути числами.\n";
            return 1;
        }
    }

    double limit = 0.0;
    std::cout << "Введіть число для порівняння: ";
    if (!(std::cin >> limit)) {
        std::cerr << "Помилка: потрібно ввести число.\n";
        return 1;
    }

    int count = 0;
    for (double value : values) {
        if (value > limit) {
            ++count;
        }
    }

    std::cout << "Кількість більших елементів: " << count << '\n';
    return 0;
}
