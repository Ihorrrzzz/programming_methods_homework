#include <iostream>
#include <vector>

using Matrix = std::vector<std::vector<double>>;

bool readMatrix(Matrix& matrix, const char* name) {
    std::cout << "Введіть елементи матриці " << name << " по рядках:\n";
    for (auto& row : matrix) {
        for (double& value : row) {
            if (!(std::cin >> value)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int rowsA = 0;
    int columnsA = 0;
    int rowsB = 0;
    int columnsB = 0;

    std::cout << "Введіть кількість рядків і стовпців матриці A: ";
    if (!(std::cin >> rowsA >> columnsA) || rowsA <= 0 || columnsA <= 0) {
        std::cerr << "Помилка: розміри мають бути додатними.\n";
        return 1;
    }
    std::cout << "Введіть кількість рядків і стовпців матриці B: ";
    if (!(std::cin >> rowsB >> columnsB) || rowsB <= 0 || columnsB <= 0) {
        std::cerr << "Помилка: розміри мають бути додатними.\n";
        return 1;
    }
    if (columnsA != rowsB) {
        std::cerr << "Помилка: кількість стовпців A має дорівнювати кількості рядків B.\n";
        return 1;
    }

    Matrix a(static_cast<std::size_t>(rowsA),
             std::vector<double>(static_cast<std::size_t>(columnsA)));
    Matrix b(static_cast<std::size_t>(rowsB),
             std::vector<double>(static_cast<std::size_t>(columnsB)));
    if (!readMatrix(a, "A") || !readMatrix(b, "B")) {
        std::cerr << "Помилка: елементи матриць мають бути числами.\n";
        return 1;
    }

    Matrix result(static_cast<std::size_t>(rowsA),
                  std::vector<double>(static_cast<std::size_t>(columnsB), 0.0));
    for (int row = 0; row < rowsA; ++row) {
        for (int column = 0; column < columnsB; ++column) {
            for (int index = 0; index < columnsA; ++index) {
                result[static_cast<std::size_t>(row)][static_cast<std::size_t>(column)] +=
                    a[static_cast<std::size_t>(row)][static_cast<std::size_t>(index)] *
                    b[static_cast<std::size_t>(index)][static_cast<std::size_t>(column)];
            }
        }
    }

    std::cout << "Добуток матриць:\n";
    for (const auto& row : result) {
        for (double element : row) {
            std::cout << element << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
