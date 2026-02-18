#include <iostream>

int main() {
    double firstNumber = 0.0;
    double secondNumber = 0.0;

    std::cout << "Введіть два числа: ";
    if (!(std::cin >> firstNumber >> secondNumber)) {
        std::cerr << "Помилка: потрібно ввести два числа.\n";
        return 1;
    }

    const double result = firstNumber * secondNumber;
    std::cout << "Добуток: " << result << '\n';
    return 0;
}
