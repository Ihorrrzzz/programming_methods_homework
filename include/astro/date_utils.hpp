#pragma once

namespace astro::date {

bool isLeapYear(int year);
int daysInMonth(int month, int year);
bool isValidDate(int day, int month, int year);
int dayOfYear(int day, int month, int year);
int daysInYear(int year);

} // namespace astro::date
