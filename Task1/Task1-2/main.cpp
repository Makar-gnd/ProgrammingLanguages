#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>


using namespace std;

/**
 * \brief
 * \param side_a (Длина первой стороны треугольника)
 * \param side_b (Длина второй стороны треугольника)
 * \param angle_rad (Значение угла между сторонами в радианах)
 * \return side_c (Длина третей стороны треугольника)
*/
double get_side_c(const double side_a, const double side_b, const double angle_rad);
/**
 * \brief
 * \param side_a (Длина первой стороны треугольника)
 * \param side_b (Длина второй стороны треугольника)
 * \param angle_rad (Значение угла между сторонами в радианах)
 * \return area (Площадь треугольника)
*/
double get_area(const double side_a, const double side_b, const double angle_rad);
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
* \param angle (Значение угла в градусах)
* \return angle_radian (значение угла в радианах)
*/
double get_angle(const double angle);
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
	const double angle_radian = get_angle(angle);
	const double area = get_area(side_a, side_b, angle_radian);
	const double side_c = get_side_c(side_a, side_b, angle_radian);
	const double radius = get_radius(side_a, side_b, side_c, area);
	cout << "side_a=" << side_a << " ,side_b=" << side_b << " ,side_c=" << side_c << " ,area=" << area << " ,radius=" << radius;
	cout << std::endl;
	return 0;
}

double get_angle(const double angle)
{
	return (angle *(M_PI/180));
}
double get_side_c(const double side_a, const double side_b, const double angle_radian)
{
	return sqrt(pow(side_a, 2) + pow(side_b, 2)) - (2 * side_a * side_b * cos(angle_radian));
}
double get_area(const double side_a, const double side_b, const double angle_radian)
{
	return ((side_a * side_b * sin((angle_radian)) / 2));
}
double get_radius(const double side_a, const double side_b, double side_c, double area)
{
	return ((side_a * side_b * side_c) / (4 * area));
}
