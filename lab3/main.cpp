#include <iostream>
#include "Array.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include "Octagon.h"

void ShowMenu()
{
    std::cout << "Выберите действие:\n"
              << "1. Добавить новую фигуру\n"
              << "2. Удалить фигуру по индексу\n"
              << "3. Показать все фигуры\n"
              << "4. Вычислить суммарную площадь всех фигур\n"
              << "5. Завершить работу\n";
}

void ShowFigureMenu()
{
    std::cout << "Выберите тип фигуры для добавления:\n"
              << "1. Пятиугольник\n"
              << "2. Шестиугольник\n"
              << "3. Восьмиугольник\n";
}

int main()
{
    Array array;
    int choice;

    while (true)
    {
        ShowMenu();
        std::cout << "Введите номер действия: ";
        std::cin >> choice;

        if (choice == 5)
        {
            std::cout << "Завершение программы. До свидания!\n";
            break;
        }

        switch (choice)
        {
        case 1:
        {
            ShowFigureMenu();
            int figureChoice;
            std::cout << "Введите номер типа фигуры: ";
            std::cin >> figureChoice;

            switch (figureChoice)
            {
            case 1:
            {
                std::cout << "Введите координаты 5 вершин для создания пятиугольника:\n";
                Pentagon p;
                std::cin >> p;
                array.AddFigure(std::make_shared<Pentagon>(p));
                break;
            }
            case 2:
            {
                std::cout << "Введите координаты 6 вершин для создания шестиугольника:\n";
                Hexagon h;
                std::cin >> h;
                array.AddFigure(std::make_shared<Hexagon>(h));
                break;
            }
            case 3:
            {
                std::cout << "Введите координаты 8 вершин для создания восьмиугольника:\n";
                Octagon o;
                std::cin >> o;
                array.AddFigure(std::make_shared<Octagon>(o));
                break;
            }
            default:
                std::cout << "Ошибка: некорректный выбор типа фигуры. Повторите попытку.\n";
                break;
            }
            break;
        }
        case 2:
        {
            size_t index;
            std::cout << "Введите индекс фигуры, которую нужно удалить: ";
            std::cin >> index;
            array.RemoveFigure(index);
            break;
        }
        case 3:
        {
            std::cout << "Список всех фигур:\n";
            array.ShowFigures();
            break;
        }
        case 4:
        {
            std::cout << "Суммарная площадь всех фигур: " << array.TotalArea() << "\n";
            break;
        }
        default:
            std::cout << "Ошибка: некорректный выбор. Повторите попытку.\n";
            break;
        }
    }
    return 0;
}
