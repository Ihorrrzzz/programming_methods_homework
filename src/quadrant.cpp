#include <iostream>

int main() {
    double x = 0.0, y = 0.0;
    std::cout << "Enter x and y: ";
    if (!(std::cin >> x >> y)) {
        std::cerr << "Invalid input." << std::endl;
        return 1;
    }

    if (x == 0.0 && y == 0.0) {
        std::cout << "The point is at the origin." << std::endl;
    } else if (x == 0.0) {
        std::cout << "The point is on the Y-axis." << std::endl;
    } else if (y == 0.0) {
        std::cout << "The point is on the X-axis." << std::endl;
    } else if (x > 0.0 && y > 0.0) {
        std::cout << "Quadrant I." << std::endl;
    } else if (x < 0.0 && y > 0.0) {
        std::cout << "Quadrant II." << std::endl;
    } else if (x < 0.0 && y < 0.0) {
        std::cout << "Quadrant III." << std::endl;
    } else {
        std::cout << "Quadrant IV." << std::endl;
    }

    return 0;
}
