#include <iostream>
using namespace std;

/**
* \brief
* \���������� �������� �� ����� �������������
* \param a ������ ����� 
* \param b ������ �����
* \return true ���� �� ��� false ���� ���
*/
bool is_positive(const int a,const int b);

/**
* \brief
* \����� ����� � ��������� 
* \return 0 � ������ ������
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
		cout << "���� ����� ����� ������ 0";
	}
	else
	{
		cout << "��� ����� ����� ������ 0";
	}
	

}
bool is_positive(int a,int b)
{
	return (a + b) > 0;
}