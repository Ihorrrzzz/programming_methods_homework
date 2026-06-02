#include <QApplication>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QWidget>

#include "astro/date_utils.hpp"

int main(int argc, char* argv[]) {
    QApplication application(argc, argv);

    QWidget window;
    window.setWindowTitle("Кількість днів у році");

    auto* dayInput = new QSpinBox(&window);
    auto* monthInput = new QSpinBox(&window);
    auto* yearInput = new QSpinBox(&window);
    dayInput->setRange(1, 31);
    monthInput->setRange(1, 12);
    yearInput->setRange(1, 9999);
    yearInput->setValue(2026);

    auto* calculateButton = new QPushButton("Обчислити", &window);
    auto* resultLabel = new QLabel("Введіть дату й натисніть «Обчислити».", &window);
    resultLabel->setWordWrap(true);

    auto* layout = new QGridLayout(&window);
    layout->addWidget(new QLabel("День:", &window), 0, 0);
    layout->addWidget(dayInput, 0, 1);
    layout->addWidget(new QLabel("Місяць:", &window), 1, 0);
    layout->addWidget(monthInput, 1, 1);
    layout->addWidget(new QLabel("Рік:", &window), 2, 0);
    layout->addWidget(yearInput, 2, 1);
    layout->addWidget(calculateButton, 3, 0, 1, 2);
    layout->addWidget(resultLabel, 4, 0, 1, 2);

    QObject::connect(calculateButton, &QPushButton::clicked, [&]() {
        const int day = dayInput->value();
        const int month = monthInput->value();
        const int year = yearInput->value();

        if (!astro::date::isValidDate(day, month, year)) {
            resultLabel->setText("Помилка: такої календарної дати не існує.");
            return;
        }

        const int ordinal = astro::date::dayOfYear(day, month, year);
        const int passed = ordinal - 1;
        const int remaining = astro::date::daysInYear(year) - ordinal;
        resultLabel->setText(
            QString("Минуло днів від початку року: %1\n"
                    "Залишилося днів до кінця року: %2")
                .arg(passed)
                .arg(remaining));
    });

    window.resize(390, 220);
    window.show();
    return application.exec();
}
