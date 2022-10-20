#include <iomanip>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

/**
 * \brief
 * \Функция расчёта колчества членов последовательности
 * \return количество членов последовательности
*/
size_t get_count(const string& message = "");

/**
 * \brief
 * \Функция расчёта суммы членов последовательности
 * \return сумма членов последовательности
*/
double get_sum(const size_t count);

/**
 * \brief
 * \Функция расчёта рекуррентного члена последовательности
 * \param k параметр Функции
 * \return значение рекуррентного члена последовательности
*/
double get_recurrent(const size_t k);

/**
* \brief 
* \Точка входа в программу
* \return 0 в случае успеха
*/
int main()
{
    setlocale(LC_ALL, "Rus");
    const auto count = get_count("Введите количество членов последовательности");
    const auto sum = get_sum(count);
    cout << "" << setprecision(9) << sum << "\n";
    return 0;
}

size_t get_count(const string& message)
{
    cout << message;
    int count;
    cin >> count;
    return count;
}

double get_sum(const size_t count)
{
    double current = 0.5;
    double sum = current;
    for (size_t k = 1; k <= count - 1; k += 1)
    {
        current = current * get_recurrent(k);
        sum = current + sum;
    }
    return sum;
}

double get_recurrent(const size_t k)
{
    return (k + 1) / (pow(k, 2) + 2 * k);
}