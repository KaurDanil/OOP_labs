#include "../include/Octagon.h"
#include <cmath>
#include <iostream>
#include <utility>

Octagon::Octagon() : vertices_(8, {0.0, 0.0}) {}

Octagon::Octagon(const std::vector<std::pair<double, double>> &vertices) : vertices_(vertices)
{
    if (vertices.size() != 8)
    {
        std::cerr << "Ошибка: должно быть передано 8 вершин для восьмиугольника." << std::endl;
        vertices_ = std::vector<std::pair<double, double>>(8, {0.0, 0.0});
    }
}

std::pair<double, double> Octagon::Center() const
{
    double x = 0.0, y = 0.0;
    for (const auto &vertex : vertices_)
    {
        x += vertex.first;
        y += vertex.second;
    }
    return {x / 8, y / 8};
}

double Octagon::Area() const
{
    return CalculateArea();
}

void Octagon::Print(std::ostream &os) const
{
    os << "Octagon vertices: ";
    for (const auto &vertex : vertices_)
    {
        os << "(" << vertex.first << ", " << vertex.second << ") ";
    }
    os << "\n";
}

void Octagon::Read(std::istream &is)
{
    vertices_.clear();
    for (int i = 0; i < 8; ++i)
    {
        double x, y;
        is >> x >> y;
        vertices_.emplace_back(x, y);
    }
}

Octagon &Octagon::operator=(const Figure &other)
{
    if (const Octagon *otherOctagon = dynamic_cast<const Octagon *>(&other))
    {
        vertices_ = otherOctagon->vertices_;
    }
    return *this;
}

bool Octagon::operator==(const Figure &other) const
{
    const Octagon *otherOctagon = dynamic_cast<const Octagon *>(&other);
    if (!otherOctagon)
        return false;
    return vertices_ == otherOctagon->vertices_;
}

double Octagon::CalculateArea() const
{
    double area = 0.0;
    for (size_t i = 0; i < vertices_.size(); ++i)
    {
        size_t j = (i + 1) % vertices_.size();
        area += vertices_[i].first * vertices_[j].second - vertices_[j].first * vertices_[i].second;
    }
    return std::abs(area) / 2.0;
}

std::ostream &operator<<(std::ostream &os, const Octagon &o)
{
    o.Print(os);
    return os;
}

std::istream &operator>>(std::istream &is, Octagon &o)
{
    o.Read(is);
    return is;
}
