#include <gtest/gtest.h>
#include "../include/Pentagon.h"
#include "../include/Hexagon.h"
#include "../include/Octagon.h"
#include <cmath>

TEST(PentagonTest, AreaCalculation)
{
    std::vector<std::pair<double, double>> vertices = {
        {2.0, 1.0},
        {1.5, 1.8},
        {-1.0, 2.0},
        {-1.5, -1.2},
        {0.5, -1.5}};
    Pentagon pentagon(vertices);

    double area = pentagon.Area();
    double expected_area = 8.725;

    EXPECT_NEAR(area, expected_area, 0.0001);
}

TEST(PentagonTest, CenterCalculation)
{
    std::vector<std::pair<double, double>> vertices = {
        {2.0, 1.0},
        {1.5, 1.8},
        {-1.0, 2.0},
        {-1.5, -1.2},
        {0.5, -1.5}};
    Pentagon pentagon(vertices);

    auto center = pentagon.Center();

    EXPECT_NEAR(center.first, 0.3, 0.0001);
    EXPECT_NEAR(center.second, 0.42, 0.0001);
}

TEST(PentagonTest, CopyConstructor)
{
    std::vector<std::pair<double, double>> vertices = {
        {2.0, 1.0},
        {1.5, 1.8},
        {-1.0, 2.0},
        {-1.5, -1.2},
        {0.5, -1.5}};
    Pentagon pentagon1(vertices);

    Pentagon pentagon2(pentagon1);

    EXPECT_TRUE(static_cast<const Figure &>(pentagon1) == static_cast<const Figure &>(pentagon2));
}

TEST(PentagonTest, AssignmentOperator)
{
    std::vector<std::pair<double, double>> vertices_1 = {
        {2.0, 1.0},
        {1.5, 1.8},
        {-1.0, 2.0},
        {-1.5, -1.2},
        {0.5, -1.5}};
    std::vector<std::pair<double, double>> vertices_2 = {
        {0.5, 1.2},
        {-1.5, 1.5},
        {-1.0, -2.0},
        {0.5, -1.5},
        {2.0, 0.0}};
    Pentagon pentagon1(vertices_1);
    Pentagon pentagon2(vertices_2);

    pentagon2 = pentagon1;

    EXPECT_TRUE(static_cast<const Figure &>(pentagon1) == static_cast<const Figure &>(pentagon2));
}

TEST(HexagonTest, AreaCalculation)
{
    std::vector<std::pair<double, double>> vertices = {
        {1.0, 0.0},
        {0.5, 0.866},
        {-0.5, 0.866},
        {-1.0, 0.0},
        {-0.5, -0.866},
        {0.5, -0.866}};
    Hexagon hexagon(vertices);

    double area = hexagon.Area();
    double expected_area = 2.598;

    EXPECT_NEAR(area, expected_area, 0.001);
}

TEST(HexagonTest, CenterCalculation)
{
    std::vector<std::pair<double, double>> vertices = {
        {1.0, 0.0},
        {0.5, 0.866},
        {-0.5, 0.866},
        {-1.0, 0.0},
        {-0.5, -0.866},
        {0.5, -0.866}};
    Hexagon hexagon(vertices);

    auto center = hexagon.Center();

    EXPECT_NEAR(center.first, 0.0, 0.0001);
    EXPECT_NEAR(center.second, 0.0, 0.0001);
}

TEST(HexagonTest, CopyConstructor)
{
    std::vector<std::pair<double, double>> vertices = {
        {1.0, 0.0},
        {0.5, 0.866},
        {-0.5, 0.866},
        {-1.0, 0.0},
        {-0.5, -0.866},
        {0.5, -0.866}};
    Hexagon hexagon1(vertices);

    Hexagon hexagon2(hexagon1);

    EXPECT_TRUE(static_cast<const Figure &>(hexagon1) == static_cast<const Figure &>(hexagon2));
}

TEST(HexagonTest, AssignmentOperator)
{
    std::vector<std::pair<double, double>> vertices_1 = {
        {1.0, 0.0},
        {0.5, 0.866},
        {-0.5, 0.866},
        {-1.0, 0.0},
        {-0.5, -0.866},
        {0.5, -0.866}};
    std::vector<std::pair<double, double>> vertices_2 = {
        {0.5, 0.5},
        {1.0, 1.0},
        {-1.0, 0.5},
        {-0.5, -1.0},
        {0.0, -0.5},
        {1.5, 0.0}};
    Hexagon hexagon1(vertices_1);
    Hexagon hexagon2(vertices_2);

    hexagon2 = hexagon1;

    EXPECT_TRUE(static_cast<const Figure &>(hexagon1) == static_cast<const Figure &>(hexagon2));
}

TEST(OctagonTest, AreaCalculation)
{
    std::vector<std::pair<double, double>> vertices = {
        {1.0, 0.0},
        {0.707, 0.707},
        {0.0, 1.0},
        {-0.707, 0.707},
        {-1.0, 0.0},
        {-0.707, -0.707},
        {0.0, -1.0},
        {0.707, -0.707}};
    Octagon octagon(vertices);

    double area = octagon.Area();
    double expected_area = 2.828;

    EXPECT_NEAR(area, expected_area, 0.0001);
}

TEST(OctagonTest, CenterCalculation)
{
    std::vector<std::pair<double, double>> vertices = {
        {1.0, 0.0},
        {0.707, 0.707},
        {0.0, 1.0},
        {-0.707, 0.707},
        {-1.0, 0.0},
        {-0.707, -0.707},
        {0.0, -1.0},
        {0.707, -0.707}};
    Octagon octagon(vertices);

    auto center = octagon.Center();

    EXPECT_NEAR(center.first, 0.0, 0.0001);
    EXPECT_NEAR(center.second, 0.0, 0.0001);
}

TEST(OctagonTest, CopyConstructor)
{
    std::vector<std::pair<double, double>> vertices = {
        {1.0, 0.0},
        {0.707, 0.707},
        {0.0, 1.0},
        {-0.707, 0.707},
        {-1.0, 0.0},
        {-0.707, -0.707},
        {0.0, -1.0},
        {0.707, -0.707}};
    Octagon octagon1(vertices);

    Octagon octagon2(octagon1);

    EXPECT_TRUE(static_cast<const Figure &>(octagon1) == static_cast<const Figure &>(octagon2));
}

TEST(OctagonTest, AssignmentOperator)
{
    std::vector<std::pair<double, double>> vertices_1 = {
        {1.0, 0.0},
        {0.707, 0.707},
        {0.0, 1.0},
        {-0.707, 0.707},
        {-1.0, 0.0},
        {-0.707, -0.707},
        {0.0, -1.0},
        {0.707, -0.707}};
    std::vector<std::pair<double, double>> vertices_2 = {
        {0.5, 0.5},
        {-1.0, 0.5},
        {-0.5, -1.0},
        {1.0, 0.0},
        {0.0, -1.5},
        {0.707, -0.707},
        {-1.0, -0.5},
        {0.5, 1.5}};
    Octagon octagon1(vertices_1);
    Octagon octagon2(vertices_2);

    octagon2 = octagon1;

    EXPECT_TRUE(static_cast<const Figure &>(octagon1) == static_cast<const Figure &>(octagon2));
}
