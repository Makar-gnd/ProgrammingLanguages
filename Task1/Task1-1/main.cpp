#include <iostream>
#include <cmath>
using namespace std;
/**
* \brief
* \param x Первый параметр функции.
* \param y Второй параметр функции.
* \param z Третий параметр функции.
* \return Значение функции.
*/
double get_a(const double x, const double y, const double z);
/**
* \brief
* \param x Первый параметр функции.
* \param y Второй параметр функции.
* \param z Третий параметр функции.
* \return Значение функции.
*/
double get_b(const double x, const double y, const double z);
/**
* \brief
* \Точка входа в программу.
* \Возвращает 0 в случае успеха.
*/
int main()
{
	const auto x = 0.5;
	const auto y = 0.05;
	const auto z = 0.7;
	const double a = get_a(x, y, z);
	const double b = get_b(x, y, z);
	cout << "a = " << a << ", b = " << b << ", x = " << x << ", y = " << y << ", z = " << z;
	cout << endl;
	return 0;
}
double get_a(const double x, const double y, const double z)
{
	return (x * x * (x + 1)) / (y - pow(sin(x + z), 2));
}

double get_b(const double x, const double y, const double z)
{
	return sqrt((x * y) / z) + pow(cos(pow(x + y, 2)), 2);
}
