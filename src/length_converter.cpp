#include <cctype>
#include <iostream>

#include "astro/units.hpp"

int main() {
    double value = 0.0;
    char unit = '\0';

    std::cout << "Введіть значення та одиницю (c — сантиметри, i — дюйми): ";
    if (!(std::cin >> value >> unit)) {
        std::cerr << "Помилка введення.\n";
        return 1;
    }

    unit = static_cast<char>(std::tolower(static_cast<unsigned char>(unit)));
    if (unit == 'c') {
        std::cout << value << " см = "
                  << astro::units::centimetersToInches(value) << " дюймів\n";
    } else if (unit == 'i') {
        std::cout << value << " дюймів = "
                  << astro::units::inchesToCentimeters(value) << " см\n";
    } else {
        std::cerr << "Помилка: використайте позначення c або i.\n";
        return 1;
    }

    return 0;
}
