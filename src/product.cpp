#include <iostream>

int main() {
    double a = 0.0, b = 0.0;
    std::cout << "Enter two numbers: ";
    if (!(std::cin >> a >> b)) {
        std::cerr << "Invalid input." << std::endl;
        return 1;
    }

    double product = a * b;
    std::cout << "Product: " << product << std::endl;
    return 0;
}
