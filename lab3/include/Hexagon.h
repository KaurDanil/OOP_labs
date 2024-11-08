#ifndef HEXAGON_H
#define HEXAGON_H

#include "Figure.h"
#include <vector>
#include <utility>
#include <iostream>

class Hexagon : public Figure
{
public:
    Hexagon();
    Hexagon(const std::vector<std::pair<double, double>> &vertices);

    std::pair<double, double> Center() const override;
    double Area() const override;
    void Print(std::ostream &os) const override;
    void Read(std::istream &is) override;

    Hexagon &operator=(const Figure &other) override;
    bool operator==(const Figure &other) const override;

    explicit operator double() const;

private:
    std::vector<std::pair<double, double>> vertices_;
    double CalculateArea() const;
};

std::ostream &operator<<(std::ostream &os, const Hexagon &h);
std::istream &operator>>(std::istream &is, Hexagon &h);

#endif // HEXAGON_H
