#ifndef PENTAGON_H
#define PENTAGON_H

#include "Figure.h"
#include <vector>

class Pentagon : public Figure
{
public:
    Pentagon();
    Pentagon(const std::vector<std::pair<double, double>> &vertices);

    std::pair<double, double> Center() const override;
    double Area() const override;
    void Print(std::ostream &os) const override;
    void Read(std::istream &is) override;

    Pentagon &operator=(const Figure &other) override;

    bool operator==(const Figure &other) const override;

private:
    std::vector<std::pair<double, double>> vertices_;
    double CalculateArea() const;
};

#endif // PENTAGON_H
