#include <iostream>
#include <cmath>
using namespace std;
/**
* \brief
* \param x �������� �������
* \return true ���� ����������
*/
bool is_exists(const double x);
/**
* \brief
* \param x �������� �������
* \return �������� ������� � ����� x
*/
double get_y(const double x);
/**
* \brief 
* \����� ����� � ��������� 
* \return 0 � ������ ������
*/
int main()
{
	const auto x_start = 0;
	const auto x_finish = 1;
	const auto step = 0.1;
	double x = x_start;
	while (x <= x_finish)
	{
		if (is_exists(x))
		{
			const double y = get_y(x);
			cout <<"x= " << x << " y= " << y << "\n";
		}
		else
		{
			cout <<"x= " << x << " y= " << "��� �������" << "\n";
		}
		x += step;
	}
	return 0;
}

bool is_exists(const double x)
{
	return true;
}

double get_y(const double x)
{
	return ((sqrt(1 - x)) - (cos(sqrt(1 - x))));
}