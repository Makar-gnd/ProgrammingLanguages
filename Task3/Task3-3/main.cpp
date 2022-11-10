#include <iostream>
#include <cmath>
#include <iomanip>
#include<string>
using namespace std;

/**
 * \brief
 * \������� ������� �������� ���������� ����� ������ ������������������
 * \param message ��������� ������������
 * \return �������� ���������� ������ ������������������
 * \exception invalid_argument ���� �������� ������ ��� ����� 0
*/
double get_epsilon(const string& message = "");

/**
 * \brief
 * \������� ������� ����� ��������������� ����
 * \param epsilon ��������� ��������
 * \param step ��� ����������
 * \return �������� ����� ��������������� ����
*/
double get_sum(const double epsilon, const double step);

/**
* \brief
 * \param x �������� �������
 * \return y �������� �������
*/
double get_y(double x);

/**
 * \brief
 * \������� ������� ��������� ������ ������������������
 * \param message ��������� ������������
 * \return h ��� ������������������
 * \exception invalid_argument ���� ��� ������ ��������� ����������
*/
double get_step(const string& message = "");

/**
 * \brief
 * \������� ������� ������������� ����� ������������������
 * \param x �������� �������
 * \param n ����� ����� ��������������� ����
 * \return �������� ������������� ����� ������������������
*/
double get_recurrent(double x, const size_t n);

/**
 * \brief
 * \����� ����� � ���������
 * \return 0 � ������ ������
*/
int main()
{  
    setlocale(LC_ALL, "Rus");

    try
    {   
        const double step = get_step("������� ��� ���������� ");
        const auto epsilon = get_epsilon("������� �������� ���������� ");

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
        throw invalid_argument("����� ������ ���� ������ " + to_string(THRESHOLD));
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
        n += 1;
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
        throw invalid_argument("����� ������ ���� ������ " + to_string(THRESHOLD));
    }

    return epsilon;
}