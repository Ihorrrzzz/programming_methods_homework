#pragma once

namespace astro::units {
// Basic astronomical constants (SI units) for quick prototypes.
// Expand or replace with authoritative sources as needed.
constexpr double kAU_m = 1.495978707e11;      // Astronomical Unit [m]
constexpr double kDay_s = 86400.0;            // Day [s]
constexpr double kJulianYear_s = 365.25 * kDay_s; // Julian year [s]
constexpr double kSpeedOfLight_m_s = 299792458.0; // c [m/s]
} // namespace astro::units
