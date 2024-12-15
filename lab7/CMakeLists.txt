cmake_minimum_required(VERSION 3.10)
project(lab_7)

# Установим стандарт языка C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Установим флаги компиляции
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -fno-stack-protector -g -O0")

# Подключение GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

# Тестовый исполняемый файл
add_executable(tests_lab7 tests/tests.cpp)

# Добавляем источники проекта в тесты
target_sources(tests_lab7 PRIVATE
    ${PROJECT_SOURCE_DIR}/npc/npc.cpp
    ${PROJECT_SOURCE_DIR}/npc/wanderingKnight.cpp
    ${PROJECT_SOURCE_DIR}/npc/slaveTrader.cpp
    ${PROJECT_SOURCE_DIR}/npc/squirrel.cpp
    ${PROJECT_SOURCE_DIR}/patterns/factory.cpp
    ${PROJECT_SOURCE_DIR}/patterns/visitor.cpp
    ${PROJECT_SOURCE_DIR}/patterns/observer.cpp
)

# Линкуем GoogleTest и создаем тесты
target_link_libraries(tests_lab7 gtest gtest_main)
include(GoogleTest)
gtest_discover_tests(tests_lab7)

# Основное приложение
add_executable(TheHungerGames
    main.cpp
    ${PROJECT_SOURCE_DIR}/npc/npc.cpp
    ${PROJECT_SOURCE_DIR}/npc/wanderingKnight.cpp
    ${PROJECT_SOURCE_DIR}/npc/slaveTrader.cpp
    ${PROJECT_SOURCE_DIR}/npc/squirrel.cpp
    ${PROJECT_SOURCE_DIR}/patterns/factory.cpp
    ${PROJECT_SOURCE_DIR}/patterns/visitor.cpp
    ${PROJECT_SOURCE_DIR}/patterns/observer.cpp
)

# Подключение include-директории
target_include_directories(TheHungerGames PRIVATE
    ${PROJECT_SOURCE_DIR}/npc
    ${PROJECT_SOURCE_DIR}/patterns
)

# Общие настройки для всех целей
target_include_directories(tests_lab7 PRIVATE
    ${PROJECT_SOURCE_DIR}/npc
    ${PROJECT_SOURCE_DIR}/patterns
)
