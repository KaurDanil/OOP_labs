#include "../include/Pentagon.h"
#include <cmath>
#include <iostream>
#include <utility>

Pentagon::Pentagon() : vertices_(5, {0.0, 0.0}) {}

Pentagon::Pentagon(const std::vector<std::pair<double, double>> &vertices) : vertices_(vertices)
{
    if (vertices.size() != 5)
    {
        std::cerr << "Ошибка: должно быть передано 5 вершин для пятиугольника." << std::endl;
        vertices_ = std::vector<std::pair<double, double>>(5, {0.0, 0.0});
    }
}

std::pair<double, double> Pentagon::Center() const
{
    double x = 0.0, y = 0.0;
    for (const auto &vertex : vertices_)
    {
        x += vertex.first;
        y += vertex.second;
    }
    return {x / 5, y / 5};
}

double Pentagon::Area() const
{
    return CalculateArea();
}

void Pentagon::Print(std::ostream &os) const
{
    os << "Pentagon vertices: ";
    for (const auto &vertex : vertices_)
    {
        os << "(" << vertex.first << ", " << vertex.second << ") ";
    }
    os << "\n";
}

void Pentagon::Read(std::istream &is)
{
    vertices_.clear();
    for (int i = 0; i < 5; ++i)
    {
        double x, y;
        is >> x >> y;
        vertices_.emplace_back(x, y);
    }
}

Pentagon &Pentagon::operator=(const Figure &other)
{
    if (const Pentagon *otherPentagon = dynamic_cast<const Pentagon *>(&other))
    {
        vertices_ = otherPentagon->vertices_;
    }
    return *this;
}

bool Pentagon::operator==(const Figure &other) const
{
    const Pentagon *otherPentagon = dynamic_cast<const Pentagon *>(&other);
    if (!otherPentagon)
        return false;
    return vertices_ == otherPentagon->vertices_;
}

double Pentagon::CalculateArea() const
{
    double area = 0.0;
    for (size_t i = 0; i < vertices_.size(); ++i)
    {
        size_t j = (i + 1) % vertices_.size();
        area += vertices_[i].first * vertices_[j].second - vertices_[j].first * vertices_[i].second;
    }
    return std::abs(area) / 2.0;
}

std::ostream &operator<<(std::ostream &os, const Pentagon &p)
{
    p.Print(os);
    return os;
}

std::istream &operator>>(std::istream &is, Pentagon &p)
{
    p.Read(is);
    return is;
}
