cmake_minimum_required(VERSION 3.10)
project(oop_lab5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Основной исполняемый файл для lab5
add_executable(main_lab5 main.cpp src/FixedBlockMemoryResource.cpp)

# Подключаем папку include для заголовочных файлов
target_include_directories(main_lab5 PRIVATE include)

# Включаем поддержку тестирования
enable_testing()

# Тестовый исполняемый файл для lab5
add_executable(tests_lab5 tests/tests.cpp src/FixedBlockMemoryResource.cpp)

# Указываем include директорию для тестов
target_include_directories(tests_lab5 PRIVATE include)

# Подключаем GoogleTest с использованием FetchContent
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

# Линкуем GoogleTest к тестам
target_link_libraries(tests_lab5 gtest gtest_main)

# Автоматическое добавление тестов для GoogleTest
include(GoogleTest)
gtest_discover_tests(tests_lab5)
