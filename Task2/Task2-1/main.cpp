#include <iostream>
#include <cmath>
using namespace std;
/**
 * \brief
 * \param a Число a.
 * \param n Число n.
 * \return Значение числа a умноженное в n раз.
 */
double get_a1(const double a, const double n);
/**
 * \brief
 * \Точка входа в программу.
 * \return 0 в случае успеха.
 */
int main()
{
    double n;
    double a;
    cout << "input a:";
    cin >> a;
    cout << "input n: ";
    cin >> n;
    double a1 = get_a1(a, n);
    cout << "a*n=";
    cout << a1;
    cout << ", a*2n=";
    cout << a1 * 2;
    cout << ", a*3n=";
    cout << a1 * 3;
    cout << endl;
    return 0;
}
double get_a1(const double a, const double n)
{
    return (a * n);
}