#include <string>
#include <iostream>
#include <exception>
#include <random>
#include <sstream>

using namespace std;

/**
 * \brief
 * \Функция заменяющая нулём элементы между максимальным и минимальным
*/
void change_elements(const size_t size, int* array);

/**
 * \brief Ввод размера
 * \param message Сообщение пользователю
 * \exception При вводе 0
 * \return Размер
*/
size_t get_size(const string& message = nullptr);

/**
 * \brief Создание массива и заполнение вручную
 * \param size Размер массива
 * \param message Сообщение пользователю
 * \return Указатель на массив
*/
int* create_array_manual(const size_t size, const string& message = nullptr);

/**
 * \brief Создание массива и заполнение случайными числами
 * \param size Размер массива
 * \param message Сообщение пользователю
 * \return Указатель на массив
*/
int* create_array_random(
    const size_t size,
    const int max = 1000,
    const int min = -1000);

/**
 * \brief
 * \param size Размер массива
 * \param array Указатель на массив
 * \return Массив в виде строки
*/
string ToString(const size_t size, int* array);

/**
 * \brief
 * \Вариант заполнения массива
*/
enum class user_choice
{
    manually,
    randomly
};

/**
 * \brief
 * \Удаление массива
 * \param array Указатель на массив
*/
void delete_array(int*& array);

/**
 * \brief Функция нахождения суммы чётных отрицательных элементов
 * \param size Размер массива
 * \param array Указатель на массив
 * \return Сумма чётных отрицательных элементов
*/
int get_sum(const size_t size, int* array);

/**
 * \brief Функция нахождения индексов элементов значения которых кратны 3 и 6
 * \param size Размер массива
 * \param array Указатель на массив элементов значения которых кратны 3 и 6
 * \return Индексы
*/
string get_index(const size_t size, int* array);

/**
 * \brief
 * \param size Размер массива
 * \param array Указатель на массив
 * \return Индекс максимального элемента
*/
int get_max_index(int* array, const size_t size);

/**
 * \brief
 * \param size Размер массива
 * \param array Указатель на массив
 * \return Индекс минимального элемента
*/
int get_min_index(int* array, const size_t size);

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
        const size_t size = get_size("Введите размер массива");
        cout << "Выберите способ заполнения массива\n" <<
            static_cast<int>(user_choice::manually) <<
            " - вручную\n" <<
            static_cast<int>(user_choice::randomly) <<
            " - случайно\n";

        auto user_choice1 = -1;
        cin >> user_choice1;
        auto choice = static_cast<user_choice>(user_choice1);
        int* array = nullptr;

        switch (choice)
        {
        case user_choice::manually:
        {
            array = create_array_manual(size, "Введите массив:\n");
            break;
        }
        case user_choice::randomly:
        {
            array = create_array_random(size);
            break;
        }
        default:
        {
            cerr << "неправильный выбор" << endl;
            return 1;
        }
        }
        cout << "Наш массив\n";
        cout << ToString(size, array);
        int sum = get_sum(size, array);
        if (sum >= 0)
        {
            cout << "В массиве нет чётных отрицательных элементов" << endl;
        }
        else
        {
            cout << "Сумма отрицательных чётных элементов = " << sum << endl;
        }
        cout << "Индексы элементов кратных 6: " << get_index(size, array);
        change_elements(size, array);
        cout << "Наш массив\n";
        cout << ToString(size, array);
        delete_array(array);
        return 0;
    }
    catch (exception& error)
    {
        cerr << error.what();
        return 1;

    }

}

size_t get_size(const string& message)
{
    int number = -1;
    cout << message;
    cin >> number;
    if (number <= 0)
    {
        throw out_of_range("Неправильный размер!");
    }
    return static_cast<size_t>(number);
}

int* create_array_manual(const size_t size, const string& message)
{
    cout << message;
    int* array = new int[size];
    for (size_t index = 0; index < size; index++)
    {
        cin >> array[index];
    }
    return array;
}

int* create_array_random(const size_t size, const int max, const int min)
{
    //Will be used to obtain a seed for the random number engine
    std::random_device rd;

    //Standard mersenne_twister_engine seeded with rd()
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> uniformIntDistribution(min, max);

    auto* array = new int[size];
    for (size_t index = 0; index < size; index++)
    {
        array[index] = uniformIntDistribution(gen);
    }

    return array;
}

string ToString(const size_t size, int* array)
{
    stringstream buffer;
    for (size_t index = 0; index < size - 1; index++)
    {
        buffer << array[index] << ", ";
    }
    buffer << array[size - 1] << "\n";

    return buffer.str();
}

void delete_array(int*& array)
{
    if (array != nullptr)
    {
        delete[] array;
        array == nullptr;
    }
}

int get_sum(const size_t size, int* array)
{
    int sum = 0;
    for (size_t index = 0; index < size; index++)
    {
        if (array[index] % 2 == 0 && array[index] < 0)
        {
            sum += array[index];
        }
    }
    return sum;
}

string get_index(const size_t size, int* array)
{
    stringstream index_6;
    for (size_t index = 0; index < size; index++)
    {
        if (array[index] % 6 == 0)
        {
            index_6 << index << ", ";
        }
    }
    return index_6.str();
}

int get_max_index(int* array, const size_t size)
{
    int max = array[0];
    int maxI = 0;
    for (size_t index = 1; index < size; index++)
    {
        if (max < array[index])
        {
            max = array[index];
            maxI = index;
        }
    }
    return maxI;
}

int get_min_index(int* array, const size_t size)
{
    int min = array[0];
    int minI = 0;
    for (size_t index = 1; index < size; index++)
    {
        if (min > array[index])
        {
            min = array[index];
            minI = index;
        }
    }
    return minI;
}

void change_elements(const size_t size, int* array)
{
    int maxI = get_max_index(array, size);
    int minI = get_min_index(array, size);
    int a = std::min(maxI, minI);
    int b = std::max(maxI, minI);
    for (size_t index = (a + 1); index < b; index++)
    {
        array[index] = 0;
    }
}