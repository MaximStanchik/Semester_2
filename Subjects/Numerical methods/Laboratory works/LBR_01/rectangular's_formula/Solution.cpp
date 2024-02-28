//Относительная погрешность можно найти по формуле :
//relative_error = | (exact_value - approximate_value) / exact_value | *100 %




#include <iostream>
#include <cmath>

using namespace std;

double fxa(double x) {
    return ((pow(sqrt(log(x) * log(x)), 1 / 3) - 3 * log(2 * x) + 5) / 5 * x);
}
double fxb(double x) {
    return (sin(x) / pow(x, 3));
}
double integralRectangles_fxa(double a, double b, double h) {
    double sum = 0;
    for (double i = a; i < b; i += h) {
        sum += h * fxa(i + h / 2);
    }
    return sum;
}
double integralRectangles_fxb(double a, double b, double h) {
    double sum = 0;
    for (double i = a; i < b; i += h) {
        sum += h * fxb(i + h / 2);
    }
    return sum;
}


int main() {
    setlocale(LC_ALL, "Russian");
    double a=0.1, b=0.5;
    int n;
    cout << "Введите количество разбиений n (или 10 или 100): ";
    cin >> n;
    double h = (b - a) / n; // ширина каждого отрезка

    double sum_fxa = integralRectangles_fxa(a, b, h);
    std::cout << "Значение первого интеграла: " << sum_fxa << std::endl;

    double sum_fxb = integralRectangles_fxb(a, b, h);
    std::cout << "Значение второго интеграла: " << sum_fxb << std::endl;
    
   /* double exact_value_fxa, exact_value_fxb;
    std::cout << "Введите точное значение интеграла a):" << std::endl;
    std::cin >> exact_value_fxa;
    std::cout << "Введите точное значение интеграла b):" << std::endl;
    std::cin >> exact_value_fxb;
    
    double relative_error_fxa = std::abs((exact_value_fxa - sum_fxa) / exact_value_fxa) * 100;
    std::cout << "Относительная погрешность первого интеграла: " << relative_error_fxa << "%" << std::endl;

    double relative_error_fxb = std::abs((exact_value_fxb - sum_fxb) / exact_value_fxb) * 100;
    std::cout << "Относительная погрешность второго интеграла: " << relative_error_fxb << "%" << std::endl;

    double absolute_error_fxa_trapecia = exact_value_fxa - sum_fxa;
    double absolute_error_fxb_trapecia = exact_value_fxb - sum_fxb;*/
    return 0;
}