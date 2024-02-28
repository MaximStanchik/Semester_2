//Задание 2.
//1. Опишите в виде структуры понятия, приведенные в таблице 1.
//2. Определите псевдонимы типов данных для полей структуры из варианта.
//3. Разработайте две операции для данных, указанного в вашем варианте типа, перегрузите операторы и продемонстрируйте их применение.

//Вариант 11
//Условие из лабораторной работы: число: тип числа(целое, действительное, комплексное); операции, применяемые к этим числам


#include<iostream>
#include <complex>
using namespace std;


typedef int whole;
typedef int valid;
typedef complex<double> comprehensive;

struct Number {
	whole X;
	valid Y;
	comprehensive Z;
};

bool operator < (Number n1, Number n2)
{
	if (n1.X < n2.X)
		return 1;
	return 0;
}

int main()
{
	setlocale(LC_ALL, "ru");
	Number numb1{50, -3367, (2.0, 3.0)};
	Number numb2{500, 10,  (-4.0, 2.0)};
	if (numb1 < numb2)
		cout << "Первое целое число меньше второго" << endl;
	else
		cout << "Первое целое число НЕ меньше второго"<<endl;
	std::cout << "Операция сложения:" << std::endl;
	std::cout << numb1.X + numb2.X;
	}



