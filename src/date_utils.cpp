#include "astro/date_utils.hpp"

namespace astro::date {

bool isLeapYear(int year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

int daysInMonth(int month, int year) {
    const int monthLengths[] = {31, 28, 31, 30, 31, 30,
                                31, 31, 30, 31, 30, 31};

    if (month < 1 || month > 12) {
        return 0;
    }

    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return monthLengths[month - 1];
}

bool isValidDate(int day, int month, int year) {
    if (year < 1) {
        return false;
    }
    return day >= 1 && day <= daysInMonth(month, year);
}

int dayOfYear(int day, int month, int year) {
    if (!isValidDate(day, month, year)) {
        return 0;
    }

    int result = day;
    for (int currentMonth = 1; currentMonth < month; ++currentMonth) {
        result += daysInMonth(currentMonth, year);
    }
    return result;
}

int daysInYear(int year) {
    return isLeapYear(year) ? 366 : 365;
}

} // namespace astro::date
