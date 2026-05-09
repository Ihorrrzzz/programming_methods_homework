#include <iostream>
#include <vector>

int main() {
    int rows = 0;
    int columns = 0;
    std::cout << "Введіть кількість рядків і стовпців матриці: ";
    if (!(std::cin >> rows >> columns) || rows <= 0 || columns <= 0) {
        std::cerr << "Помилка: розміри матриці мають бути додатними.\n";
        return 1;
    }

    std::vector<std::vector<double>> matrix(
        static_cast<std::size_t>(rows),
        std::vector<double>(static_cast<std::size_t>(columns)));

    std::cout << "Введіть елементи матриці по рядках:\n";
    int zeroCount = 0;
    for (auto& row : matrix) {
        for (double& value : row) {
            if (!(std::cin >> value)) {
                std::cerr << "Помилка: елементи матриці мають бути числами.\n";
                return 1;
            }
            if (value == 0.0) {
                ++zeroCount;
            }
        }
    }

    std::cout << "Кількість нульових елементів: " << zeroCount << '\n';
    return 0;
}
