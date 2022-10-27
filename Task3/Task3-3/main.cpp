#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

/**
 * \brief
 * \param x параметр функции
 * \return y значение функции
*/
double get_y(double x);

/**
 * \brief
 * \функция расчёта рекуррентного члена последовательности
 * \param x параметр функции
 * \param n номер члена функционального ряда
 * \return значение рекуррентного члена последовательности
*/
double get_recurrent(double x, const size_t n);

/**
 * \brief
 * \точка входа в программу
 * \return 0 в случае успеха
*/
int main()
{  
    setlocale(LC_ALL, "Rus");
    const auto x_start = 0.2;
    const auto x_finish = 1;
    auto x = x_start;
    double h;
    cout << "Введите значение шага h= ";
    cin >> h;
    while (x < x_finish)
    {
        double y = get_y(x);
        cout << setprecision(6) << "x=" << x << " y=" << y<<"\n";
        x += h;
    }
    return 0;
}

double get_y(double x)
{
    return log(x) / 2;
}

double get_recurrent(double x, size_t n)
{
    return (2 * n * pow(x, 2) - 4 * n * x + 2 * n + pow(x, 2) - 2 * x + 1) / (2 * n * pow(x, 2) + 4 * n * x + 2 * n + 3 * pow(x, 2) + 6 * x + 3);
}

