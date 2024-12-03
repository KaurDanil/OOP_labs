cmake_minimum_required(VERSION 3.10)
project(Lab_6)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Определение директорий для исходников и заголовочных файлов
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)

# Включение директории с заголовочными файлами
include_directories(${INCLUDE_DIR})

# Сборка исходных файлов
file(GLOB SOURCES "${SOURCE_DIR}/*.cpp")

# Основное исполнимое
add_executable(${CMAKE_PROJECT_NAME}_exe main.cpp ${SOURCES})

# Включение заголовочных файлов для основного исполнимого
target_include_directories(${CMAKE_PROJECT_NAME}_exe PUBLIC ${INCLUDE_DIR})
    
# Интеграция с GoogleTest через FetchContent
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

# Добавляем тесты
add_executable(${CMAKE_PROJECT_NAME}_tests ${TEST_DIR}/test.cpp ${SOURCES})

# Включаем заголовочные файлы для тестов
target_include_directories(${CMAKE_PROJECT_NAME}_tests PRIVATE ${INCLUDE_DIR})

# Линкуем тесты с библиотеками GTest
target_link_libraries(${CMAKE_PROJECT_NAME}_tests gtest gtest_main pthread)

# Включаем тестирование
enable_testing()

# Автоматическое обнаружение тестов
include(GoogleTest)
gtest_discover_tests(${CMAKE_PROJECT_NAME}_tests)
