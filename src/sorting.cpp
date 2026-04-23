#include <iostream>
#include <utility>
#include <vector>

void bubbleSort(std::vector<double>& values) {
    for (std::size_t unsortedSize = values.size(); unsortedSize > 1; --unsortedSize) {
        bool changed = false;
        for (std::size_t index = 1; index < unsortedSize; ++index) {
            if (values[index - 1] > values[index]) {
                std::swap(values[index - 1], values[index]);
                changed = true;
            }
        }
        if (!changed) {
            break;
        }
    }
}

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

    bubbleSort(values);

    std::cout << "Відсортований масив:";
    for (double value : values) {
        std::cout << ' ' << value;
    }
    std::cout << '\n';
    return 0;
}
