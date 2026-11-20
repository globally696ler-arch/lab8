#include "geometry.h"
#include <cmath>
#include <stdexcept>
#include <iostream>
#include <iomanip>

namespace geometry
{
    // Площадь круга: π * r^2
    double circleArea(double radius, double pi)
    {
        if (radius < 0 || pi <= 0) // Проверяем корректность входных данных: радиус не может быть отрицательным, а π — нулевым или отрицательным
            throw std::invalid_argument("circleArea: радиус и pi должны быть положительными");
        return pi * radius * radius;
    }
    // Площадь прямоугольника: width * height
    double rectangleArea(double width, double height)
    {
        if (width < 0 || height < 0) // Стороны не могут быть отрицательными
            throw std::invalid_argument("rectangleArea: стороны не могут быть отрицательными");
        return width * height;
    }
    // Площадь треугольника по основанию и высоте: 1/2 * base * height
    double triangleArea(double base, double height)
    {
        if (base < 0 || height < 0) // Допускаются нулевые значения (площадь = 0), но не отрицательные
            throw std::invalid_argument("triangleArea: основание и высота должны быть >= 0");
        return 0.5 * base * height;
    }
    // Площадь треугольника по трём сторонам (формула Герона)
    double triangleArea(double a, double b, double c)
    {
        if (a <= 0 || b <= 0 || c <= 0)
            throw std::invalid_argument("triangleArea: стороны должны быть > 0");

        // Проверка неравенства треугольника: сумма любых двух сторон должна быть больше третьей
        if (a + b <= c || a + c <= b || b + c <= a)
            throw std::invalid_argument("triangleArea: стороны не образуют треугольник");

        // Формула Герона
        double p = (a + b + c) / 2.0; // полупериметр
        return std::sqrt(p * (p - a) * (p - b) * (p - c));
    }

}

int main()
{
    std::cout << std::fixed << std::setprecision(4); // Фиксированный формат: 4 знака после запятой

    // Круг: точность π по умолчанию (полная) и «урезанная» (3.14)
    std::cout << "Круг r=5, pi по умолчанию : " << geometry::circleArea(5) << "\n";
    std::cout << "Круг r=5, pi=3.14         : " << geometry::circleArea(5, 3.14) << "\n";

    // Прямоугольник и квадрат
    std::cout << "Прямоугольник 4 x 6       : " << geometry::rectangleArea(4, 6) << "\n";
    std::cout << "Квадрат 4                 : " << geometry::rectangleArea(4) << "\n";

    // Треугольник: по основанию и высоте и по трём сторонам
    std::cout << "Треугольник b=6, h=4      : " << geometry::triangleArea(6, 4) << "\n";
    std::cout << "Треугольник 3, 4, 5       : " << geometry::triangleArea(3, 4, 5) << "\n";

    return 0;
}