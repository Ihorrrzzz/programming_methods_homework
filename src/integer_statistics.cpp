#include <array>
#include <cstdlib>
#include <iostream>

constexpr std::size_t kNumberCount = 10;

int main() {
    std::array<long long, kNumberCount> numbers{};
    std::cout << "Введіть " << kNumberCount << " цілих чисел: ";

    for (long long& number : numbers) {
        if (!(std::cin >> number)) {
            std::cerr << "Помилка: потрібно вводити цілі числа.\n";
            return 1;
        }
    }

    int evenCount = 0;
    int positiveCount = 0;
    int multiDigitCount = 0;

    for (long long number : numbers) {
        if (number % 2 == 0) {
            ++evenCount;
        }
        if (number > 0) {
            ++positiveCount;
        }
        if (number > 9 || number < -9) {
            ++multiDigitCount;
        }
    }

    std::cout << "Парних чисел: " << evenCount << '\n';
    std::cout << "Додатних чисел: " << positiveCount << '\n';
    std::cout << "Багатоцифрових чисел: " << multiDigitCount << '\n';
    return 0;
}
