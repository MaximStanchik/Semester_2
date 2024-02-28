//Вариант 24





#include<iostream> // добавляем функции для ввода и вывода на экран
#include <math.h> // добавляем математические функции
#include <conio.h> //попробовать найти встроенную функцию в с++ которая будет решать интеграл если не найду нужно будет убрать часть кода с погрешностями
double fxa(double x) {
	return ((pow(sqrt(log(x) * log(x)), 1 / 3) - 3 * log(2 * x) + 5) / 5 * x);
}
double fxb(double x) {
	return (sin(x) / pow(x, 3));
}

int main(){
	setlocale(LC_ALL, "Russian");
	double Integral; // здесь будет интеграл
	double a = 3, b = 7; // задаём отрезок интегрирования
	int h1 = 10, h2 = 100;// задаём шаг интегрирования. h1--делим отрезок сначала на 10, h2--потом отрезок делим на 100
	double n1, n2, n; // задаём число разбиений n
	int h, k, i, l, H;
	n1 = (b - a) / h1; 
	n2 = (b - a) / h2;
	std::cout << "Введите пожалуйста следующие значения: " << std::endl;
	std::cout << "1--если Вы хотите вычислить интегралы а) и б) с шагом интегрирования h1=10" << std::endl;
	std::cout << "2--если Вы хотите вычислить интегралы а) и б) с шагом интегрирования h2=100" << std::endl;
	std::cout << "Нажатие любой другой клавиши--если Вы хотите выйти из программы" << std::endl;
	std::cin >> k;
	switch (k) {
	case 1:
		h = h1;
		n = n1;
		break;
	case 2:
		h = h2;
		n = n2;
		break;
	default:
		std::cout << "Благодарим за использование нашего приложения" << std::endl;
		return 0;
	}
	/*double A;
	double B;
	std::cout << "Введите точное значение интеграла а)" << std::endl;
	std::cin >> A;
	std::cout << "Введите точное значение интеграла b)" << std::endl;
	std::cin >> B;*/
	std::cout << "Вычисление интегралов по формуле симпсона:" << std::endl;

	Integral = h * (fxa(a) + fxa(b)) / 6.0;
	for (i = 1; i <= n; i++)
		Integral = Integral + 4.0 / 6.0 * h * fxa(a + h * (i - 0.5)); //прочитать теорию особенно про точки 
	for (i = 1; i <= n - 1; i++)
		Integral = Integral + 2.0 / 6.0 * h * fxa(a + h * i);
	std::cout << "Посчитанный интегралл a) = " << Integral << "\n";
	/*double absolute_error_fxa_trapecia = A - Integral;*/
	/*std::cout << "Абсолютная погрешность первого интеграла: " << absolute_error_fxa_trapecia << std::endl;
	double relative_error_fxa = std::abs((A - Integral) / A) * 100;
	std::cout << "Относительная погрешность первого интеграла: " << relative_error_fxa << "%" << std::endl;*/
	Integral = 0;

	Integral = h * (fxb(a) + fxb(b)) / 6.0;
	for (l = 1; l <= n; l++)
		Integral = Integral + 4.0 / 6.0 * h * fxb(a + h * (l - 0.5));
	for (l = 1; l <= n - 1; l++)
		Integral = Integral + 2.0 / 6.0 * h * fxb(a + h * l);
	std::cout << "Посчитанный интегралл b) = " << Integral << "\n";
	/*double absolute_error_fxb_trapecia = B - Integral;
	std::cout <<"Абсолютная погрешность второго интеграла: " << absolute_error_fxb_trapecia << std::endl;
	relative_error_fxa = std::abs((B - Integral) / B) * 100;
	std::cout << "Относительная погрешность второго интеграла: " << relative_error_fxa << "%" << std::endl;*/

	Integral = 0;

	std::cout << "Вычисление интегралов по формуле трапеций:" << std::endl;

	Integral = h * (fxa(a) + fxa(b)) / 2.0;
	for (i = 1; i <= n - 1; i++)
		Integral = Integral + h * fxa(a + h * i);
	Integral = Integral / 3;
	std::cout << "Посчитанный интегралл a) = " << Integral << "\n";
	/*absolute_error_fxa_trapecia = A - Integral;
	std::cout << "Абсолютная погрешность первого интеграла: " << absolute_error_fxa_trapecia << std::endl;
	relative_error_fxa = std::abs((A - Integral) / A) * 100;
	std::cout << "Относительная погрешность первого интеграла: " << relative_error_fxa << "%" << std::endl;*/

	Integral = h * (fxb(a) + fxb(b)) / 2.0;
	for (i = 1; i <= n - 1; i++)
		Integral = Integral + h * fxb(a + h * i);
	Integral = Integral / 3;
	std::cout << "Посчитанный интегралл b) = " << Integral << "\n";
	/*absolute_error_fxb_trapecia = B - Integral;
	std::cout << "Абсолютная погрешность второго интеграла: " << absolute_error_fxb_trapecia << std::endl;
	relative_error_fxa = std::abs((B - Integral) / B) * 100;
	std::cout << "Относительная погрешность второго интеграла: " << relative_error_fxa << "%" << std::endl;*/

	return 0;
}








