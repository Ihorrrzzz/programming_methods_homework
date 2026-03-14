#pragma once

namespace astro::units {
// Базові астрономічні сталі в одиницях SI.
constexpr double kAstronomicalUnitMeters = 1.495978707e11;
constexpr double kDaySeconds = 86400.0;
constexpr double kJulianYearSeconds = 365.25 * kDaySeconds;
constexpr double kSpeedOfLightMetersPerSecond = 299792458.0;

// Попередні імена залишено для сумісності з початковими прикладами проєкту.
constexpr double kAU_m = kAstronomicalUnitMeters;
constexpr double kDay_s = kDaySeconds;
constexpr double kJulianYear_s = kJulianYearSeconds;
constexpr double kSpeedOfLight_m_s = kSpeedOfLightMetersPerSecond;

constexpr double kCentimetersPerInch = 2.54;

constexpr double inchesToCentimeters(double inches) {
    return inches * kCentimetersPerInch;
}

constexpr double centimetersToInches(double centimeters) {
    return centimeters / kCentimetersPerInch;
}
} // namespace astro::units
