cmake_minimum_required(VERSION 3.20)
project(programming_methods_homework LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(ASTRO_ENABLE_WARNINGS "Enable common compiler warnings" ON)
option(ASTRO_ENABLE_WERROR "Treat warnings as errors" OFF)
option(ASTRO_BUILD_QT "Build the Qt date application when Qt is available" ON)

add_library(astro_core INTERFACE)
target_include_directories(astro_core INTERFACE ${PROJECT_SOURCE_DIR}/include)

function(astro_apply_common_settings target_name)
    target_link_libraries(${target_name} PRIVATE astro_core)

    if(ASTRO_ENABLE_WARNINGS)
        if(MSVC)
            target_compile_options(${target_name} PRIVATE /W4)
        else()
            target_compile_options(${target_name} PRIVATE -Wall -Wextra -Wpedantic)
        endif()
    endif()

    if(ASTRO_ENABLE_WERROR)
        if(MSVC)
            target_compile_options(${target_name} PRIVATE /WX)
        else()
            target_compile_options(${target_name} PRIVATE -Werror)
        endif()
    endif()
endfunction()

function(add_homework target_name source_file)
    add_executable(${target_name} ${source_file})
    astro_apply_common_settings(${target_name})
endfunction()

add_homework(product src/product.cpp)
add_homework(polar src/polar.cpp)
add_homework(quadrant src/quadrant.cpp)
add_homework(triangle_geometry src/triangle_geometry.cpp)

add_library(date_utils src/date_utils.cpp)
astro_apply_common_settings(date_utils)

add_executable(day_of_year src/day_of_year.cpp)
target_link_libraries(day_of_year PRIVATE date_utils)
astro_apply_common_settings(day_of_year)

add_homework(quadratic_equation src/quadratic_equation.cpp)
add_homework(length_converter src/length_converter.cpp)
add_homework(double_factorial src/double_factorial.cpp)
add_homework(taylor_series src/taylor_series.cpp)
add_homework(symbol_triangles src/symbol_triangles.cpp)
add_homework(rectangular_tables src/rectangular_tables.cpp)
add_homework(zero_vector_components src/zero_vector_components.cpp)
add_homework(integer_statistics src/integer_statistics.cpp)
add_homework(vector_dot_angle src/vector_dot_angle.cpp)
add_homework(count_greater src/count_greater.cpp)
add_homework(reverse_order src/reverse_order.cpp)
add_homework(sorting src/sorting.cpp)
add_homework(longest_increasing_run src/longest_increasing_run.cpp)
add_homework(matrix_multiplication src/matrix_multiplication.cpp)
add_homework(zero_matrix_elements src/zero_matrix_elements.cpp)
add_homework(determinant src/determinant.cpp)
add_homework(word_frequency src/word_frequency.cpp)

add_library(figure_core
    src/Figure.cpp
    src/Figure.h
    src/Ellipse.cpp
    src/Ellipse.h
    src/Rectangle.cpp
    src/Rectangle.h
)
target_include_directories(figure_core PUBLIC ${PROJECT_SOURCE_DIR}/src)
astro_apply_common_settings(figure_core)

add_executable(figure_ellipse src/main.cpp)
target_link_libraries(figure_ellipse PRIVATE figure_core)
astro_apply_common_settings(figure_ellipse)

# Rectangle збережено як окремий аудиторний приклад.
add_executable(rectangle_example src/rectangle_main.cpp)
target_link_libraries(rectangle_example PRIVATE figure_core)
astro_apply_common_settings(rectangle_example)
