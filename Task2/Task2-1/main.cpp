#include <iostream>
#include <cmath>
using namespace std;
/**
 * \brief
 * \param A Число A.
 * \param N Число N.
 * \return Значение числа A умноженное в N раз.
 */
double get_A1(double A, double N);
/**
 * \brief
 * \Точка входа в программу.
 * \return 0 в случае успеха.
 */
int main()
{
    double N;
    double A;
    cout << "input A:";
    cin >> A;
    cout << "input N: ";
    cin >> N;
    double A1 = get_A1(A, N);
    cout << "A*N=";
    cout << A1;
    cout << ", A*2N=";
    cout << A1 * 2;
    cout << ", A*3N=";
    cout << A1 * 3;
    cout << endl;
    return 0;
}
double get_A1(double A, double N)
{
    return (A * N);
}