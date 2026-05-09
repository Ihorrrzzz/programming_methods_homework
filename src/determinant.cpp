#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using Matrix = std::vector<std::vector<double>>;

double calculateDeterminant(Matrix matrix) {
    const std::size_t size = matrix.size();
    double determinant = 1.0;
    int sign = 1;

    // Метод Гауса з вибором найбільшого опорного елемента зменшує похибку.
    for (std::size_t column = 0; column < size; ++column) {
        std::size_t pivotRow = column;
        for (std::size_t row = column + 1; row < size; ++row) {
            if (std::abs(matrix[row][column]) > std::abs(matrix[pivotRow][column])) {
                pivotRow = row;
            }
        }

        if (std::abs(matrix[pivotRow][column]) < 1e-12) {
            return 0.0;
        }
        if (pivotRow != column) {
            std::swap(matrix[pivotRow], matrix[column]);
            sign = -sign;
        }

        const double pivot = matrix[column][column];
        determinant *= pivot;
        for (std::size_t row = column + 1; row < size; ++row) {
            const double factor = matrix[row][column] / pivot;
            for (std::size_t currentColumn = column + 1;
                 currentColumn < size; ++currentColumn) {
                matrix[row][currentColumn] -= factor * matrix[column][currentColumn];
            }
        }
    }

    return static_cast<double>(sign) * determinant;
}

int main() {
    int size = 0;
    std::cout << "Введіть розмір квадратної матриці: ";
    if (!(std::cin >> size) || size <= 0) {
        std::cerr << "Помилка: розмір має бути додатним цілим числом.\n";
        return 1;
    }

    Matrix matrix(static_cast<std::size_t>(size),
                  std::vector<double>(static_cast<std::size_t>(size)));
    std::cout << "Введіть елементи матриці по рядках:\n";
    for (auto& row : matrix) {
        for (double& value : row) {
            if (!(std::cin >> value)) {
                std::cerr << "Помилка: елементи матриці мають бути числами.\n";
                return 1;
            }
        }
    }

    std::cout << std::setprecision(12);
    std::cout << "Визначник: " << calculateDeterminant(matrix) << '\n';
    return 0;
}
