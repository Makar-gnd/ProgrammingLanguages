#include <iostream>
#include <cmath>
using namespace std;
/**
* \brief 
* \param a (Первый параметр функции)
* \param x (Второй параметр функции)
* \return (Значение функции при условии (a*x)<1) 
*/
double get_y1(const double a,const double x);
/**
* \brief
* \param a (Первый параметр функции)
* \param x (Второй параметр функции)
* \return (Значение функции при условии (a*x)>=1)
*/
double get_y2(const double a, const double x);
/**
* \brief
* \Точка входа в программу
* \return 0 в случае успеха
*/
int main()
{
	double y;
	double x;
	cout << "x=";
	cin >> x;
	const double a = 1.5;
	if ((a * x) < 1)
	{
		y = get_y1(a, x);
	}
	else
	{
		y = get_y2(a, x);
	}
	cout << "y= ";
	cout << y;
	cout << endl;
	return 0;
}
double get_y1(const double a, const double x)
{
	return ((a * x) - log10(a * x));
}
double get_y2(const double a, const double x)
{
	return ((a * x) + log10(a * x));
}
