#include <iostream>

#include "astro/date_utils.hpp"

bool expectEqual(int actual, int expected, const char* testName) {
    if (actual == expected) {
        return true;
    }

    std::cerr << "Не пройдено тест " << testName << ": отримано "
              << actual << ", очікувалося " << expected << '\n';
    return false;
}

int main() {
    bool success = true;
    success &= expectEqual(astro::date::dayOfYear(1, 1, 2026), 1, "перший день року");
    success &= expectEqual(astro::date::dayOfYear(1, 3, 2024), 61, "високосний рік");
    success &= expectEqual(astro::date::dayOfYear(31, 12, 2026), 365, "останній день року");
    success &= expectEqual(astro::date::dayOfYear(29, 2, 2025), 0, "некоректна дата");
    success &= expectEqual(astro::date::daysInYear(2000), 366, "рік, кратний 400");
    success &= expectEqual(astro::date::daysInYear(1900), 365, "рік, кратний 100");

    if (!success) {
        return 1;
    }

    std::cout << "Усі перевірки дат пройдено.\n";
    return 0;
}
