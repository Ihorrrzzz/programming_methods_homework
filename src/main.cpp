#include <iostream>

#include "astro/units.hpp"

int main() {
    std::cout << "Astronomy C++ sandbox\n";
    std::cout << "1 AU = " << astro::units::kAU_m << " m\n";
    return 0;
}
