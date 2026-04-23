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
    std::cout << "Введіть елементи: ";
    for (double& value : values) {
        if (!(std::cin >> value)) {
            std::cerr << "Помилка: елементи мають бути числами.\n";
            return 1;
        }
    }

    std::cout << "У зворотному порядку:";
    for (auto iterator = values.rbegin(); iterator != values.rend(); ++iterator) {
        std::cout << ' ' << *iterator;
    }
    std::cout << '\n';
    return 0;
}
