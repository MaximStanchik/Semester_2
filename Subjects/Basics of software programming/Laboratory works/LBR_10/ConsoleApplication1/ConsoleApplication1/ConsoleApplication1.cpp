#include <iostream>
using namespace std;

double Sn(double n, double x) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 2 * x;
    }
    else if (n < 0) {
        cout << "Вы ввели некоректное значение n. Функция не будет работать." << endl;
        return 0;
    }
    else if (n > 1) {
        return (2 * n / (n - 1)) * Sn(n - 1, x) + ((n - 1) / (2 * n)) * Sn(n - 2, x);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    double n;
    double x;
    cout << "Введите значение n: ";
    cin >> n;
    if (n != round(n)) {
        cout << "Введено дробное число. Программа не будет работать" << endl;
    }
    else {
        cout << "Введите значение x: ";
        cin >> x;
        cout << "Sn(" << n << ", " << x << ") = " << Sn(n, x) << endl;
    }
    return 0;
}
