

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




//метод деления отрезка пополам:
#include <iostream>
#include <cmath>
#include <iomanip> 
using namespace std;

float eps = 0.01; 

double f(double x)
{
    return x * x * x + 8 * x - 6;
}

double bisection(double a, double b, float eps) { // метод деления отрезка пополам
    double x0 = (a + b) / 2;
    while (abs(b - a) > eps) {
        if (f(x0) == 0) {
            return x0;
        }
        else if (f(a) * f(x0) < 0) {
            b = x0;
        }
        else {
            a = x0;
        }
        x0 = (a + b) / 2;
    }
    return x0;
}

int main() {
    setlocale(LC_ALL, "Russian");
    float a, b, A; //А--для случая когда надо поменять а и b местами
    double X; //X--примерное значение х
    cout << "Введите значение а: ";
    cin >> a;
    cout << "Введите значение b: ";
    cin >> b;
    if (a > b) // если перепутали границы отрезка, меняем их местами
    {
        A = a;
        a = b;
        b = A;
    }
    cout << "Введите примерное значение х: ";
    cin >> X;
    if (X > a && X < b) {
        double root = bisection(a, b, eps);
        cout << "Корень: " << root << endl;
    }
    else {
        cout << "Вы ввели неправильные значения отрезка или Х" << endl;
        cout << "Программа закончит свое выполнение" << endl;
        return 0;
    }
    return 0;
}


