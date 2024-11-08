#include "Array.h"
#include <iostream>

void Array::AddFigure(std::shared_ptr<Figure> figure)
{
    figures_.push_back(figure);
}

void Array::RemoveFigure(size_t index)
{
    if (index < figures_.size())
    {
        figures_.erase(figures_.begin() + index);
    }
}

void Array::ShowFigures() const
{
    for (const auto &figure : figures_)
    {
        std::cout << *figure << "Center: " << figure->Center().first << ", " << figure->Center().second << "\n";
    }
}

double Array::TotalArea() const
{
    double totalArea = 0;
    for (const auto &figure : figures_)
    {
        totalArea += figure->Area();
    }
    return totalArea;
}
