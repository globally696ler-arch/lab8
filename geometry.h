#ifndef GEOMETRY_H
#define GEOMETRY_H
namespace geometry
{
    constexpr double DEFAULT_PI = 3.14159265358979323846;

    // Площадь круга
    double circleArea(double radius, double pi = DEFAULT_PI);

    // Площадь прямоугольника
    double rectangleArea(double width, double height);
    inline double rectangleArea(double side) { return rectangleArea(side, side); }

    // Площадь треугольника
    double triangleArea(double base, double height);
    double triangleArea(double a, double b, double c);

}

#endif