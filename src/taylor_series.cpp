#include <cmath>
#include <iomanip>
#include <iostream>

constexpr int kMaximumIterations = 10000;
constexpr double kTolerance = 1e-15;

double expSeriesForPositive(double x) {
    double sum = 1.0;
    double term = 1.0;

    for (int n = 1; n <= kMaximumIterations; ++n) {
        term *= x / static_cast<double>(n);
        sum += term;
        if (std::abs(term) < kTolerance * std::abs(sum)) {
            break;
        }
    }
    return sum;
}

double expTaylor(double x) {
    if (x < 0.0) {
        return 1.0 / expSeriesForPositive(-x);
    }
    return expSeriesForPositive(x);
}

double sinTaylor(double x) {
    const double pi = std::acos(-1.0);
    const double reducedX = std::remainder(x, 2.0 * pi);
    double sum = reducedX;
    double term = reducedX;

    for (int n = 1; n <= kMaximumIterations; ++n) {
        const double denominator = static_cast<double>((2 * n) * (2 * n + 1));
        term *= -reducedX * reducedX / denominator;
        sum += term;
        if (std::abs(term) < kTolerance) {
            break;
        }
    }
    return sum;
}

int main() {
    double x = 0.0;
    std::cout << "Введіть x: ";
    if (!(std::cin >> x)) {
        std::cerr << "Помилка: x має бути числом.\n";
        return 1;
    }

    const double calculatedExp = expTaylor(x);
    const double calculatedSin = sinTaylor(x);

    std::cout << std::setprecision(15);
    std::cout << "exp(x) за рядом Тейлора: " << calculatedExp << '\n';
    std::cout << "exp(x) зі стандартної бібліотеки: " << std::exp(x) << '\n';
    std::cout << "sin(x) за рядом Тейлора: " << calculatedSin << '\n';
    std::cout << "sin(x) зі стандартної бібліотеки: " << std::sin(x) << '\n';
    return 0;
}
