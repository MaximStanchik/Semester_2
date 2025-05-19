
//fstream--универсальный класс, который делает все что ifstream и ofstream
//ifstream--input file stream--чтение данных из файла
//ofstream--output file stream--возможность сохранения данных в файл


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums; // вектор для хранения чисел из файла
    int num;
    ifstream fileA("fileA.txt"); // открытие файла для чтения
    if (!fileA.is_open()) // проверка на успешное открытие файла
    {
        cout << "Ошибка открытия файла!" << endl;
        return 1; //завершение выполнения функции и возвращает элемент управления в вызывающую функцию
    }
    while (fileA >> num) // чтение чисел из файла, идет сдвиг вправо
    {
        nums.push_back(num); // добавление числа в вектор
    }
    fileA.close(); // закрытие файла
    ofstream fileB("fileB.txt"); // открытие файла для записи
    if (!fileB.is_open()) // проверка на успешное открытие файла
    {
        cout << "Ошибка открытия файла!" << endl;
        return 1; //завершение выполнения функции и возвращает элемент управления в вызывающую функцию
    }
    for (int i = 0; i < nums.size(); i++) // перебор всех чисел из вектора
    {
        int count = 0; // счетчик повторений числа в векторе
        for (int j = 0; j < nums.size(); j++) // перебор всех чисел из вектора
        {
            if (nums[i] == nums[j]) // если числа совпадают
            {
                count++; // увеличиваем счетчик
            }
        }
        if (count == 2) // если число встречается ровно 2 раза
        {
            fileB << nums[i] << " "; // записываем число в файл
        }
    }
    fileB.close(); // закрытие файла
    return 0;
}


