//Разработать лямбда-функцию, которая принимает две строки и возвращает ту строку, которая длиннее.

#include <iostream>
#include <string>

using namespace std;

bool toDefinePositiveOrNot(double number)
{
    auto checkPositive = [](double number) {
        return number > 0;
    };

    return checkPositive(number);
}

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Это задание 1:" << endl;

    double number;
    cout << "Введите число: ";
    cin >> number;
    if (number == 0) {
        cout << "Число неотрицательное." << endl;
    }

    if (toDefinePositiveOrNot(number)) {
        cout << "Число положительное." << endl;
    }
    else {
        cout << "Число не положительное." << endl;
    }

    cout << "Это задание 4:" << endl;

    string str1, str2;

    cout << "Введите первую строку: ";
    getline(cin, str1);

    cout << "Введите вторую строку: ";
    getline(cin, str2);

    auto longer = [&str1, &str2]() {
        return str1.length() > str2.length();
    };

    if (longer()) {
        cout << "Первая строка длиннее" << endl;
    }
    else if (longer()) {
        cout << "Вторая строка длиннее" << endl;
    }
    else {
        cout << "Строки одинаковы по длинне" << endl;
    }

    return 0;
}








