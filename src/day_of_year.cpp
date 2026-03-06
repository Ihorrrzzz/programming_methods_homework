#include <iostream>
#include <sstream>
#include <string>

#include "astro/date_utils.hpp"

int main() {
    std::string dateText;
    std::cout << "Введіть дату у форматі дд/мм/рррр: ";
    if (!std::getline(std::cin, dateText)) {
        std::cerr << "Помилка читання дати.\n";
        return 1;
    }

    std::istringstream input(dateText);
    int day = 0;
    int month = 0;
    int year = 0;
    char firstSeparator = '\0';
    char secondSeparator = '\0';
    char extraCharacter = '\0';

    if (!(input >> day >> firstSeparator >> month >> secondSeparator >> year)
        || firstSeparator != '/' || secondSeparator != '/'
        || (input >> extraCharacter)) {
        std::cerr << "Помилка: дата повинна мати формат дд/мм/рррр.\n";
        return 1;
    }

    if (!astro::date::isValidDate(day, month, year)) {
        std::cerr << "Помилка: такої календарної дати не існує.\n";
        return 1;
    }

    std::cout << "Порядковий номер дня: "
              << astro::date::dayOfYear(day, month, year) << '\n';
    return 0;
}
