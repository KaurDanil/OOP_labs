#include "array.hpp"
#include "figure.hpp"
#include "functions.hpp"
#include "gtest/gtest.h"
#include "hexagon.hpp"
#include "octagon.hpp"
#include "pentagon.hpp"

// Pentagon double tests

std::vector<std::pair<double, double>> v1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
std::vector<std::pair<double, double>> v2 = {{6, 6}, {7, 7}, {8, 8}, {9, 9}, {10, 10}};

TEST(Pentagon_double, empty_constructor)
{
    Pentagon<double> p;
    std::pair<double, double> center{0, 0};
    std::pair<double, double> res = fig::getMidPoint<Pentagon<double>, double>(p);
    double surf = fig::surface<Pentagon<double>, double>(p);
    EXPECT_EQ(res, center);
    EXPECT_EQ(surf, 0);
}

TEST(Pentagon_double, vector_constructor)
{
    Pentagon<double> p(v1);
    std::pair<double, double> center{3, 3};
    std::pair<double, double> res = fig::getMidPoint<Pentagon<double>, double>(p);
    EXPECT_EQ(p.points, v1);
    EXPECT_EQ(res, center);
}

TEST(Pentagon_double, equality)
{
    Pentagon<double> p1(v1);
    Pentagon<double> p2(v1);
    Pentagon<double> p3(v2);
    EXPECT_EQ(p1, p2);
    EXPECT_FALSE(p1 == p3);
}

// Pentagon float tests

std::vector<std::pair<float, float>> v3 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
std::vector<std::pair<float, float>> v4 = {{6, 6}, {7, 7}, {8, 8}, {9, 9}, {10, 10}};

TEST(Pentagon_float, empty_constructor)
{
    Pentagon<float> p;
    std::pair<float, float> center{0, 0};
    std::pair<float, float> res = fig::getMidPoint<Pentagon<float>, float>(p);
    float surf = fig::surface<Pentagon<float>, float>(p);
    EXPECT_EQ(res, center);
    EXPECT_EQ(surf, 0);
}

TEST(Pentagon_float, vector_constructor)
{
    Pentagon<float> p(v3);
    std::pair<float, float> center{3, 3};
    std::pair<float, float> res = fig::getMidPoint<Pentagon<float>, float>(p);
    EXPECT_EQ(p.points, v3);
    EXPECT_EQ(res, center);
}

TEST(Pentagon_float, equality)
{
    Pentagon<float> p1(v3);
    Pentagon<float> p2(v3);
    Pentagon<float> p3(v4);
    EXPECT_EQ(p1, p2);
    EXPECT_FALSE(p1 == p3);
}

// Pentagon int tests

std::vector<std::pair<int, int>> v5 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
std::vector<std::pair<int, int>> v6 = {{6, 6}, {7, 7}, {8, 8}, {9, 9}, {10, 10}};

TEST(Pentagon_int, empty_constructor)
{
    Pentagon<int> p;
    std::pair<int, int> center{0, 0};
    std::pair<int, int> res = fig::getMidPoint<Pentagon<int>, int>(p);
    int surf = fig::surface<Pentagon<int>, int>(p);
    EXPECT_EQ(res, center);
    EXPECT_EQ(surf, 0);
}

TEST(Pentagon_int, vector_constructor)
{
    Pentagon<int> p(v5);
    std::pair<int, int> center{3, 3};
    std::pair<int, int> res = fig::getMidPoint<Pentagon<int>, int>(p);
    EXPECT_EQ(p.points, v5);
    EXPECT_EQ(res, center);
}

TEST(Pentagon_int, equality)
{
    Pentagon<int> p1(v5);
    Pentagon<int> p2(v5);
    Pentagon<int> p3(v6);
    EXPECT_EQ(p1, p2);
    EXPECT_FALSE(p1 == p3);
}

// Hexagon double tests

std::vector<std::pair<double, double>> v7 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}};
std::vector<std::pair<double, double>> v8 = {{7, 7}, {8, 8}, {9, 9}, {10, 10}, {11, 11}, {12, 12}};

TEST(Hexagon_double, empty_constructor)
{
    Hexagon<double> h;
    std::pair<double, double> center{0, 0};
    std::pair<double, double> res = fig::getMidPoint<Hexagon<double>, double>(h);
    double surf = fig::surface<Hexagon<double>, double>(h);
    EXPECT_EQ(res, center);
    EXPECT_EQ(surf, 0);
}

TEST(Hexagon_double, vector_constructor)
{
    Hexagon<double> h(v7);
    std::pair<double, double> center{3.5, 3.5};
    std::pair<double, double> res = fig::getMidPoint<Hexagon<double>, double>(h);
    EXPECT_EQ(h.points, v7);
    EXPECT_EQ(res, center);
}

TEST(Hexagon_double, equality)
{
    Hexagon<double> h1(v7);
    Hexagon<double> h2(v7);
    Hexagon<double> h3(v8);
    EXPECT_EQ(h1, h2);
    EXPECT_FALSE(h1 == h3);
}

// Hexagon float tests

std::vector<std::pair<float, float>> v9 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}};
std::vector<std::pair<float, float>> v10 = {{7, 7}, {8, 8}, {9, 9}, {10, 10}, {11, 11}, {12, 12}};

TEST(Hexagon_float, empty_constructor)
{
    Hexagon<float> h;
    std::pair<float, float> center{0, 0};
    std::pair<float, float> res = fig::getMidPoint<Hexagon<float>, float>(h);
    float surf = fig::surface<Hexagon<float>, float>(h);
    EXPECT_EQ(res, center);
    EXPECT_EQ(surf, 0);
}

TEST(Hexagon_float, vector_constructor)
{
    Hexagon<float> h(v9);
    std::pair<float, float> center{3.5, 3.5};
    std::pair<float, float> res = fig::getMidPoint<Hexagon<float>, float>(h);
    EXPECT_EQ(h.points, v9);
    EXPECT_EQ(res, center);
}

TEST(Hexagon_float, equality)
{
    Hexagon<float> h1(v9);
    Hexagon<float> h2(v9);
    Hexagon<float> h3(v10);
    EXPECT_EQ(h1, h2);
    EXPECT_FALSE(h1 == h3);
}

// Hexagon int tests

std::vector<std::pair<int, int>> v11 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}};
std::vector<std::pair<int, int>> v12 = {{7, 7}, {8, 8}, {9, 9}, {10, 10}, {11, 11}, {12, 12}};

TEST(Hexagon_int, empty_constructor)
{
    Hexagon<int> h;
    std::pair<int, int> center{0, 0};
    std::pair<int, int> res = fig::getMidPoint<Hexagon<int>, int>(h);
    int surf = fig::surface<Hexagon<int>, int>(h);
    EXPECT_EQ(res, center);
    EXPECT_EQ(surf, 0);
}

TEST(Hexagon_int, vector_constructor)
{
    Hexagon<int> h(v11);
    std::pair<int, int> center{3, 3};
    std::pair<int, int> res = fig::getMidPoint<Hexagon<int>, int>(h);
    EXPECT_EQ(h.points, v11);
    EXPECT_EQ(res, center);
}

TEST(Hexagon_int, equality)
{
    Hexagon<int> h1(v11);
    Hexagon<int> h2(v11);
    Hexagon<int> h3(v12);
    EXPECT_EQ(h1, h2);
    EXPECT_FALSE(h1 == h3);
}

// Octagon double tests

std::vector<std::pair<double, double>> v13 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}, {8, 8}};
std::vector<std::pair<double, double>> v14 = {{9, 9}, {10, 10}, {11, 11}, {12, 12}, {13, 13}, {14, 14}, {15, 15}, {16, 16}};

TEST(Octagon_double, empty_constructor)
{
    Octagon<double> o;
    std::pair<double, double> center{0, 0};
    std::pair<double, double> res = fig::getMidPoint<Octagon<double>, double>(o);
    double surf = fig::surface<Octagon<double>, double>(o);
    EXPECT_EQ(res, center);
    EXPECT_EQ(surf, 0);
}

TEST(Octagon_double, vector_constructor)
{
    Octagon<double> o(v13);
    std::pair<double, double> center{4.5, 4.5};
    std::pair<double, double> res = fig::getMidPoint<Octagon<double>, double>(o);
    EXPECT_EQ(o.points, v13);
    EXPECT_EQ(res, center);
}

TEST(Octagon_double, equality)
{
    Octagon<double> o1(v13);
    Octagon<double> o2(v13);
    Octagon<double> o3(v14);
    EXPECT_EQ(o1, o2);
    EXPECT_FALSE(o1 == o3);
}

// Octagon float tests

std::vector<std::pair<float, float>> v15 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}, {8, 8}};
std::vector<std::pair<float, float>> v16 = {{9, 9}, {10, 10}, {11, 11}, {12, 12}, {13, 13}, {14, 14}, {15, 15}, {16, 16}};

TEST(Octagon_float, empty_constructor)
{
    Octagon<float> o;
    std::pair<float, float> center{0, 0};
    std::pair<float, float> res = fig::getMidPoint<Octagon<float>, float>(o);
    float surf = fig::surface<Octagon<float>, float>(o);
    EXPECT_EQ(res, center);
    EXPECT_EQ(surf, 0);
}

TEST(Octagon_float, vector_constructor)
{
    Octagon<float> o(v15);
    std::pair<float, float> center{4.5, 4.5};
    std::pair<float, float> res = fig::getMidPoint<Octagon<float>, float>(o);
    EXPECT_EQ(o.points, v15);
    EXPECT_EQ(res, center);
}

TEST(Octagon_float, equality)
{
    Octagon<float> o1(v15);
    Octagon<float> o2(v15);
    Octagon<float> o3(v16);
    EXPECT_EQ(o1, o2);
    EXPECT_FALSE(o1 == o3);
}

// Octagon int tests

std::vector<std::pair<int, int>> v17 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}, {8, 8}};
std::vector<std::pair<int, int>> v18 = {{9, 9}, {10, 10}, {11, 11}, {12, 12}, {13, 13}, {14, 14}, {15, 15}, {16, 16}};

TEST(Octagon_int, empty_constructor)
{
    Octagon<int> o;
    std::pair<int, int> center{0, 0};
    std::pair<int, int> res = fig::getMidPoint<Octagon<int>, int>(o);
    int surf = fig::surface<Octagon<int>, int>(o);
    EXPECT_EQ(res, center);
    EXPECT_EQ(surf, 0);
}

TEST(Octagon_int, vector_constructor)
{
    Octagon<int> o(v17);
    std::pair<int, int> center{4, 4};
    std::pair<int, int> res = fig::getMidPoint<Octagon<int>, int>(o);
    EXPECT_EQ(o.points, v17);
    EXPECT_EQ(res, center);
}

TEST(Octagon_int, equality)
{
    Octagon<int> o1(v17);
    Octagon<int> o2(v17);
    Octagon<int> o3(v18);
    EXPECT_EQ(o1, o2);
    EXPECT_FALSE(o1 == o3);
}

// Array tests

TEST(Array, common_surface)
{
    Array<Pentagon<double>> a(2);
    Pentagon<double> *p1 = new Pentagon<double>();
    Pentagon<double> *p2 = new Pentagon<double>();
    a[0] = *p1;
    a[1] = *p2;
    EXPECT_EQ(a.common_surface(), 0.0);
}