#include <iostream>
#include <string>

int main() {
    int height = 0;
    std::cout << "Введіть висоту трикутників n: ";
    if (!(std::cin >> height) || height <= 0) {
        std::cerr << "Помилка: n має бути додатним цілим числом.\n";
        return 1;
    }

    std::cout << "Перший трикутник:\n";
    for (int row = 1; row <= height; ++row) {
        std::cout << std::string(static_cast<std::size_t>(row), '*') << '\n';
    }

    std::cout << "Другий трикутник:\n";
    for (int row = 1; row <= height; ++row) {
        const auto spaces = static_cast<std::size_t>(height - row);
        const auto stars = static_cast<std::size_t>(row);
        std::cout << std::string(spaces, ' ') << std::string(stars, '*') << '\n';
    }

    return 0;
}
