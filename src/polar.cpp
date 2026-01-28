#include <iostream>
#include <cmath>

int main() {
    double x = 0.0, y = 0.0;
    std::cout << "Enter x and y: ";
    if (!(std::cin >> x >> y)) {
        std::cerr << "Invalid input." << std::endl;
        return 1;
    }

    double r = std::sqrt(x * x + y * y);
    double angle = std::atan2(y, x); // radians

    std::cout << "Radius: " << r << std::endl;
    std::cout << "Angle (radians): " << angle << std::endl;
    return 0;
}
