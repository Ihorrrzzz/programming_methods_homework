#include <array>
#include <iostream>

constexpr std::size_t kVectorSize = 5;

int main() {
    std::array<double, kVectorSize> values{};
    std::cout << "Введіть " << kVectorSize << " компонентів вектора: ";

    for (double& value : values) {
        if (!(std::cin >> value)) {
            std::cerr << "Помилка: усі компоненти мають бути числами.\n";
            return 1;
        }
    }

    int zeroCount = 0;
    for (double value : values) {
        if (value == 0.0) {
            ++zeroCount;
        }
    }

    std::cout << "Кількість нульових компонентів: " << zeroCount << '\n';
    return 0;
}
