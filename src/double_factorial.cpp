#include <iostream>
#include <limits>

int main() {
    int number = 0;
    std::cout << "Введіть невід'ємне ціле число N: ";
    if (!(std::cin >> number) || number < 0) {
        std::cerr << "Помилка: N має бути невід'ємним цілим числом.\n";
        return 1;
    }

    unsigned long long result = 1;
    for (int factor = number; factor > 1; factor -= 2) {
        const auto unsignedFactor = static_cast<unsigned long long>(factor);
        if (result > std::numeric_limits<unsigned long long>::max() / unsignedFactor) {
            std::cerr << "Помилка: результат не вміщується в тип unsigned long long.\n";
            return 1;
        }
        result *= unsignedFactor;
    }

    std::cout << number << "!! = " << result << '\n';
    return 0;
}
