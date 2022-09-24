#include <iostream>
#include <cmath>
using namespace std;
/**
* \brief
* \param x ������ �������� �������.
* \param y ������ �������� �������.
* \param z ������ �������� �������.
* \return �������� �������.
*/
double get_a(const double x, const double y, const double z);
/**
* \brief
* \param x ������ �������� �������.
* \param y ������ �������� �������.
* \param z ������ �������� �������.
* \return �������� �������.
*/
double get_b(const double x, const double y, const double z);
/**
* \brief
* \����� ����� � ���������.
* \���������� 0 � ������ ������.
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
