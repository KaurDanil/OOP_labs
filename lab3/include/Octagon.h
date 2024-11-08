#ifndef OCTAGON_H
#define OCTAGON_H

#include "Figure.h"
#include <vector>
#include <utility>
#include <iostream>

class Octagon : public Figure
{
public:
    Octagon();
    Octagon(const std::vector<std::pair<double, double>> &vertices);

    std::pair<double, double> Center() const override;
    double Area() const override;
    void Print(std::ostream &os) const override;
    void Read(std::istream &is) override;

    Octagon &operator=(const Figure &other) override;
    bool operator==(const Figure &other) const override;

    explicit operator double() const;

private:
    std::vector<std::pair<double, double>> vertices_;
    double CalculateArea() const;
};

std::ostream &operator<<(std::ostream &os, const Octagon &o);
std::istream &operator>>(std::istream &is, Octagon &o);

#endif // OCTAGON_H
