#include <iostream>

int main() {
    double x = 0.0, y = 0.0;
    std::cout << "Enter x and y: ";
    if (!(std::cin >> x >> y)) {
        std::cerr << "Invalid input." << std::endl;
        return 1;
    }

    const std::string result =
        (x == 0.0 && y == 0.0) ? "The point is at the origin." :
        (x == 0.0) ? "The point is on the Y-axis." :
        (y == 0.0) ? "The point is on the X-axis." :
        (x > 0.0 && y > 0.0) ? "Quadrant I." :
        (x < 0.0 && y > 0.0) ? "Quadrant II." :
        (x < 0.0 && y < 0.0) ? "Quadrant III." : "Quadrant IV.";

    std::cout << result << std::endl;

    double a = x > 0 ? x : -x;

    return 0;
}
