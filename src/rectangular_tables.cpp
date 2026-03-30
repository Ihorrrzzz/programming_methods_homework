#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

void printTable(const std::vector<std::vector<int>>& table, int width) {
    for (const auto& row : table) {
        for (int value : row) {
            std::cout << std::setw(width) << value << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    int rows = 0;
    int columns = 0;
    std::cout << "Введіть кількість рядків n і стовпців m: ";
    if (!(std::cin >> rows >> columns) || rows <= 0 || columns <= 0) {
        std::cerr << "Помилка: розміри таблиці мають бути додатними.\n";
        return 1;
    }

    std::vector<std::vector<int>> regular(
        static_cast<std::size_t>(rows),
        std::vector<int>(static_cast<std::size_t>(columns)));
    std::vector<std::vector<int>> snake = regular;

    int value = 1;
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            regular[static_cast<std::size_t>(row)][static_cast<std::size_t>(column)] = value;
            ++value;
        }
    }

    value = 1;
    for (int row = 0; row < rows; ++row) {
        for (int position = 0; position < columns; ++position) {
            const int column = row % 2 == 0 ? position : columns - position - 1;
            snake[static_cast<std::size_t>(row)][static_cast<std::size_t>(column)] = value;
            ++value;
        }
    }

    const int width = static_cast<int>(std::to_string(rows * columns).size());
    std::cout << "Послідовне заповнення:\n";
    printTable(regular, width);
    std::cout << "Заповнення змійкою:\n";
    printTable(snake, width);
    return 0;
}
