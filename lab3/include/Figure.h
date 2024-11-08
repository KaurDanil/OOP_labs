#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <memory>
#include <utility>

class Figure
{
public:
    virtual ~Figure() = default;

    virtual Figure &operator=(const Figure &other)
    {
        return *this;
    }

    virtual std::pair<double, double> Center() const = 0;

    virtual double Area() const = 0;

    virtual void Print(std::ostream &os) const = 0;

    virtual void Read(std::istream &is) = 0;

    operator double() const
    {
        return Area();
    }

    virtual bool operator==(const Figure &other) const = 0;
};

inline std::ostream &operator<<(std::ostream &os, const Figure &figure)
{
    figure.Print(os);
    return os;
}

inline std::istream &operator>>(std::istream &is, Figure &figure)
{
    figure.Read(is);
    return is;
}

#endif // FIGURE_H
