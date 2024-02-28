//Вариант 24
//x^3+8*x-6=0
//точность 0.01
//x=0.625
//a=0
//b=1
                                                               //Задание:
                                      //Определить корни уравнения графически и уточнить один из них ите-
                                      //рационными методами(методом деления отрезка пополам, методом Нью -
                                      //тона, методом простой итерации) с точностью 0,01:



#include <iostream>
#include <cmath>
#include <iomanip> //разобраться для чего нужна

using namespace std;

double eps = 0.01;

double f(double x)
{
    return x * x * x + 8 * x - 6;
}

double N(double x) {
    return (x * x * x * (-1) + 6)/8;
}

double df_1(double x) { // первая производная функции
    return 3 * x * x + 8;
}

int main() {
    setlocale(LC_ALL, "Russian");
    double M;
    double x;
    cout << "Введите начальное приближение корня" << endl;
    cin >> x;
    /*M = 1.01 * df_1(x);
    if (N(x) == (x - f(x)) / M) {*/
    while (abs(f(x)) > eps) {
        x = N(x);
    }
    cout << "Приблизительное знаечние корня: " << x << endl;
    return 0;
}