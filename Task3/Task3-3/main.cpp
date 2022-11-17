#include <iostream>
#include <cmath>
#include <iomanip>
#include<string>
using namespace std;

/**
 * \brief
 * \Функция расчёта точности вычисления суммы членов последовательности
 * \param message сообщение пользователю
 * \return точность вычисления членов последовательности
 * \exception invalid_argument если точность меньше или равна 0
*/
double get_epsilon(const string& message = "");

/**
 * \brief
 * \Функция расчёта суммы функционального ряда
 * \param epsilon пороговое значение
 * \param step шаг вычисления
 * \return значение суммы функционального ряда
*/
double get_sum(const double epsilon, const double step);

/**
* \brief
 * \param x параметр функции
 * \return y значение функции
*/
double get_y(double x);

/**
 * \brief
 * \Функция расчёта колчества членов последовательности
 * \param message сообщение пользователю
 * \return h шаг последовательности
 * \exception invalid_argument если шаг больше заданного промежутка
*/
double get_step(const string& message = "");

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

    try
    {   
        const double step = get_step("Введите шаг вычисления ");
        const auto epsilon = get_epsilon("Введите точность вычисления ");

        double current = -0.76;
        const auto x_finish = 1;
        const auto x_start = 0.2;
        auto x = x_start;

        double sum = get_sum(epsilon,step);
        while (x < x_finish)
        {
            double y = get_y(x);
            cout << setprecision(9) << "x= " << x << " y= " << y <<" y1="<<current << "\n";
            current = current * sum;
            x += step; 
        }
    }
    catch (invalid_argument const& ex)
    {
        cerr << ex.what(); 
        return 1;
    }

    return 0;
}

double get_recurrent(double x, size_t n)
{
    return (2 * n * pow(x, 2) - 4 * n * x + 2 * n + pow(x, 2) - 2 * x + 1) / (2 * n * pow(x, 2) + 4 * n * x + 2 * n + 3 * pow(x, 2) + 6 * x + 3);
}

double get_step(const string& message)
{
    cout << message;
    const double THRESHOLD = 0.8;
    auto step = THRESHOLD;
    cin >> step;

    if (step > THRESHOLD)
    {
        throw invalid_argument("Число должно быть больше " + to_string(THRESHOLD));
    }

    return step;
}

double get_y(double x)
{
    return log(x) / 2;
}

double get_sum(const double epsilon, const double step)
{
    double sum = 0.0;
    double x = 0.2;
    size_t n = 1;
    while (abs(get_recurrent(x, n)) > epsilon)
    {
        sum += get_recurrent(x, n);
        n ++;
        x += step;
    }
    return sum;
}

double get_epsilon(const string& message)
{
    const auto THRESHOLD = 0.0;
    cout << message;

    auto epsilon = 1e-5;
    cin >> epsilon;

    if (epsilon < THRESHOLD)
    {
        throw invalid_argument("Число должно быть больше " + to_string(THRESHOLD));
    }

    return epsilon;
}