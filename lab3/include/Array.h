#ifndef ARRAY_H
#define ARRAY_H

#include "Figure.h"
#include <vector>
#include <memory>

class Array
{
public:
    void AddFigure(std::shared_ptr<Figure> figure);
    void RemoveFigure(size_t index);
    void ShowFigures() const;
    double TotalArea() const;

private:
    std::vector<std::shared_ptr<Figure>> figures_;
};

#endif // ARRAY_H
