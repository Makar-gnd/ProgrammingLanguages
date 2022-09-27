#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>


using namespace std;

/**
 * \brief
 * \param side_a (Длина первой стороны треугольника)
 * \param side_b (Длина второй стороны треугольника)
 * \param angle (Значение угла между сторонами в градусах)
 * \return side_c (Длина третей стороны треугольника)
*/
double get_side_c(const double side_a, const double side_b, const double angle);
/**
 * \brief
 * \param side_a (Длина первой стороны треугольника)
 * \param side_b (Длина второй стороны треугольника)
 * \param angle (Значение угла между сторонами в градусах)
 * \return area (Площадь треугольника)
*/
double get_area(const double side_a, const double side_b, const double angle);
/**
* \brief
* \param side_a (Длина первой стороны треугольника)
* \param side_b (Длина второй стороны треугольника)
* \param side_c (Длина третей стороны)
* \param area (Площадь треугольника)
* \return radius (Длина радиуса описанной окружности треугольника)
*/
double get_radius(const double side_a, const double side_b, const double side_c, double area);
/**
* \brief
* \Точка входа в программу.
* \return 0 в случае успеха.
*/
int main()
{
	double side_a;
	double side_b;
	double angle;
	cout << "input a :";
	cin >> side_a;
	cout << "input b:";
	cin >> side_b;
	cout << "input angle in degrees:";
	cin >> angle;
	const double area = get_area(side_a, side_b, angle);
	const double side_c = get_side_c(side_a, side_b, angle);
	const double radius = get_radius(side_a, side_b, side_c, area);
	cout << "side_a=" << side_a << " ,side_b=" << side_b << " ,side_c=" << side_c << " ,area=" << area << " ,radius=" << radius;
	cout << std::endl;
	return 0;
}
double get_side_c(const double side_a, const double side_b, const double angle)
{
	return sqrt(pow(side_a, 2) + pow(side_b, 2)) - (2 * side_a * side_b * cos(angle * M_PI / 180));
}
double get_area(const double side_a, const double side_b, const double angle)
{
	return ((side_a * side_b * sin((angle * M_PI / 180)) / 2));
}
double get_radius(const double side_a, const double side_b, double side_c, double area)
{
	return ((side_a * side_b * side_c) / (4 * area));
}
