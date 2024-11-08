#include "../include/Hexagon.h"
#include <cmath>
#include <iostream>
#include <utility>

Hexagon::Hexagon() : vertices_(6, {0.0, 0.0}) {}

Hexagon::Hexagon(const std::vector<std::pair<double, double>> &vertices) : vertices_(vertices)
{
    if (vertices.size() != 6)
    {
        std::cerr << "Ошибка: должно быть передано 6 вершин для шестиугольника." << std::endl;
        vertices_ = std::vector<std::pair<double, double>>(6, {0.0, 0.0});
    }
}

std::pair<double, double> Hexagon::Center() const
{
    double x = 0.0, y = 0.0;
    for (const auto &vertex : vertices_)
    {
        x += vertex.first;
        y += vertex.second;
    }
    return {x / 6, y / 6};
}

double Hexagon::Area() const
{
    return CalculateArea();
}

void Hexagon::Print(std::ostream &os) const
{
    os << "Hexagon vertices: ";
    for (const auto &vertex : vertices_)
    {
        os << "(" << vertex.first << ", " << vertex.second << ") ";
    }
    os << "\n";
}

void Hexagon::Read(std::istream &is)
{
    vertices_.clear();
    for (int i = 0; i < 6; ++i)
    {
        double x, y;
        is >> x >> y;
        vertices_.emplace_back(x, y);
    }
}

Hexagon &Hexagon::operator=(const Figure &other)
{
    if (const Hexagon *otherHexagon = dynamic_cast<const Hexagon *>(&other))
    {
        vertices_ = otherHexagon->vertices_;
    }
    return *this;
}

bool Hexagon::operator==(const Figure &other) const
{
    const Hexagon *otherHexagon = dynamic_cast<const Hexagon *>(&other);
    if (!otherHexagon)
        return false;
    return vertices_ == otherHexagon->vertices_;
}

double Hexagon::CalculateArea() const
{
    double area = 0.0;
    for (size_t i = 0; i < vertices_.size(); ++i)
    {
        size_t j = (i + 1) % vertices_.size();
        area += vertices_[i].first * vertices_[j].second - vertices_[j].first * vertices_[i].second;
    }
    return std::abs(area) / 2.0;
}

std::ostream &operator<<(std::ostream &os, const Hexagon &h)
{
    h.Print(os);
    return os;
}

std::istream &operator>>(std::istream &is, Hexagon &h)
{
    h.Read(is);
    return is;
}
