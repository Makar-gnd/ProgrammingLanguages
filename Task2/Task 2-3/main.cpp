#include <iostream>
using namespace std;

/**
* \brief
* \Определяет является ли сумма положительной
* \param a первое число 
* \param b второе число
* \return true если да или false если нет
*/
bool is_positive(const int a,const int b);

/**
* \brief
* \Точка входа в программу 
* \return 0 в случае успеха
*/
int main()
{
	setlocale(LC_ALL, "RU");

	int a = 0;
	cout << "a= ";
	cin >> a;
	int b = 0;
	cout << "b= ";
	cin >> b;
	int c = 0;
	cout << "c= ";
	cin >> c;
	if (is_positive(a, b)   > 0 && is_positive(a, c) > 0 && is_positive(b, c) > 0)
	{
		cout << "Есть сумма чисел больше 0";
	}
	else
	{
		cout << "Нет суммы чисел больше 0";
	}
	

}
bool is_positive(int a,int b)
{
	return (a + b) > 0;
}