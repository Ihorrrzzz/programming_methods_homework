#!/usr/bin/env bash

set -euo pipefail

build_dir="$1"
source_dir="$2"
checked=0

run_check() {
    local executable="$1"
    local input="$2"
    local expected="$3"
    local output

    output=$(printf '%b' "$input" | "$build_dir/$executable" 2>&1)
    if [[ "$output" != *"$expected"* ]]; then
        echo "Помилка перевірки $executable"
        echo "$output"
        exit 1
    fi
    checked=$((checked + 1))
}

run_check product '3 4\n' 'Добуток: 12'
run_check polar '3 4\n' 'Радіус: 5'
run_check quadrant '-2 3\n' 'II чверті'
run_check triangle_geometry '0 0 3 0 0 4\n' 'Площа: 6.000000'
run_check day_of_year '29/02/2024\n' 'Порядковий номер дня: 60'
run_check quadratic_equation '1 -3 2\n' 'x1 = 2'
run_check length_converter '5 i\n' '12.7 см'
run_check double_factorial '7\n' '7!! = 105'
run_check taylor_series '1\n' '2.718281828'
run_check symbol_triangles '4\n' '****'
run_check rectangular_tables '3 4\n' '12 '
run_check zero_vector_components '0 1 0 2 3\n' 'Кількість нульових компонентів: 2'
run_check integer_statistics '1 2 -10 0 11 12 -3 4 5 6\n' 'Багатоцифрових чисел: 3'
run_check vector_dot_angle '2\n1 0\n0 1\n' '90.000000 градусів'
run_check count_greater '5\n1 5 3 8 2\n3\n' 'Кількість більших елементів: 2'
run_check reverse_order '4\n1 2 3 4\n' '4 3 2 1'
run_check sorting '5\n4 1 5 2 3\n' '1 2 3 4 5'
run_check longest_increasing_run '5 6 10 1 9 4 3 8 15 19 34 8 2 0\n' '3 8 15 19 34'
run_check matrix_multiplication '2 3\n3 2\n1 2 3 4 5 6\n7 8 9 10 11 12\n' '58 64'
run_check zero_matrix_elements '2 3\n0 1 0 2 3 0\n' 'Кількість нульових елементів: 3'
run_check determinant '2\n1 2 3 4\n' 'Визначник: -2'
run_check figure_ellipse '3 2\n' 'Периметр (наближення Рамануджана)'
run_check rectangle_example '' 'Площа: 20'

word_output=$("$build_dir/word_frequency" "$source_dir/data/sample_text.txt")
if [[ "$word_output" != *'apple: 5'* ]]; then
    echo "Помилка перевірки word_frequency"
    echo "$word_output"
    exit 1
fi
checked=$((checked + 1))

echo "Успішно перевірено консольних програм: $checked"
