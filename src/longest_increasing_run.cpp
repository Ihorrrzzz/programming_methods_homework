#include <iostream>
#include <vector>

int main() {
    std::vector<double> sequence;
    std::cout << "Вводьте числа послідовності (0 завершує введення): ";

    double value = 0.0;
    while (std::cin >> value && value != 0.0) {
        sequence.push_back(value);
    }

    if (!std::cin && !std::cin.eof()) {
        std::cerr << "Помилка: послідовність повинна містити числа.\n";
        return 1;
    }
    if (sequence.empty()) {
        std::cout << "Послідовність порожня.\n";
        return 0;
    }

    std::size_t bestStart = 0;
    std::size_t bestLength = 1;
    std::size_t currentStart = 0;

    for (std::size_t index = 1; index < sequence.size(); ++index) {
        if (sequence[index] <= sequence[index - 1]) {
            currentStart = index;
        }

        const std::size_t currentLength = index - currentStart + 1;
        if (currentLength > bestLength) {
            bestStart = currentStart;
            bestLength = currentLength;
        }
    }

    std::cout << "Найдовший неперервний зростаючий фрагмент:";
    for (std::size_t index = bestStart; index < bestStart + bestLength; ++index) {
        std::cout << ' ' << sequence[index];
    }
    std::cout << '\n';
    return 0;
}
