#include <iostream>

int main() {
    double x = 0.0;
    double y = 0.0;

    std::cout << "Введіть координати x та y: ";
    if (!(std::cin >> x >> y)) {
        std::cerr << "Помилка: координати мають бути числами.\n";
        return 1;
    }

    if (x == 0.0 && y == 0.0) {
        std::cout << "Точка розташована в початку координат.\n";
    } else if (x == 0.0) {
        std::cout << "Точка розташована на осі Y.\n";
    } else if (y == 0.0) {
        std::cout << "Точка розташована на осі X.\n";
    } else if (x > 0.0 && y > 0.0) {
        std::cout << "Точка розташована у I чверті.\n";
    } else if (x < 0.0 && y > 0.0) {
        std::cout << "Точка розташована у II чверті.\n";
    } else if (x < 0.0 && y < 0.0) {
        std::cout << "Точка розташована у III чверті.\n";
    } else {
        std::cout << "Точка розташована у IV чверті.\n";
    }

    return 0;
}
