#include <iomanip>
#include <string>
#include <iostream>
#include <cmath>
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
 * \Функция расчёта колчества членов последовательности
 * \param message сообщение пользователю
 * \return количество членов последовательности
 * \exception invalid_argument если количество меньше 1
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
 * \Расчёт суммы последовательности
 * \param epsilon точность вычисления
 * \return сумма членов последовательности
*/
double get_sum(const double epsilon);

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
    try
    {
        const auto count = get_count("Введите количество членов последовательности ");
        auto sum = get_sum(count);
        cout << setprecision(9)<< "Сумма " << count << " членов последовательности = " << sum << "\n";
        
        const auto epsilon = get_epsilon("Введите точность вычисления");
        sum = get_sum(epsilon);
        cout << setprecision(9) << "Сумма " << count << " членов последовательности c заданной точностью = " << sum << "\n";
    }
    catch (invalid_argument const& ex)
    {
        cerr << ex.what();
        return 1;

    }
    return 0;
}

size_t get_count(const string& message)
{
    cout << message;

    const auto THRESHOLD = 1;
    int count = THRESHOLD;
    cin >> count;

    if (count < THRESHOLD)
    {
        throw invalid_argument("Число должно быть больше " + to_string(THRESHOLD));
    }

    return count;
}

double get_sum(const size_t count)
{
    double current = 0.5;
    auto sum = current;

    for (size_t k = 1; k < count; k += 1)
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

double get_sum(const double epsilon)
{
    auto current = 0.5;
    auto sum = current;
    size_t k = 1;

    while (abs(current) > epsilon)
    {
        current = current * get_recurrent(k);
        sum = current + sum;
        k += 1;
    }
    return sum;
}