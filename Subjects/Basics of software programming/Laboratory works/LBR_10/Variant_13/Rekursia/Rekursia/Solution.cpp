#include <iostream>
using namespace std;

int dnx(int n, int x) {
    if (x == 1) { // базовый случай
        return 1;
    }
    else if (n % x == 0 && x > 1) { // если x является делителем n
        return dnx(n, x - 1) + 1;
    }
    else { // если x не является делителем n
        return dnx(n, x - 1);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    double n_double;
    int x;
    double x_double;
    cout << "Введите натуральное число n: ";
    cin>> n_double;
    if (n_double != round(n_double)) {
        cout << "Введено дробное число. Программа не будет работать" << endl;
        return 0;
    }
    else if (n_double <= 0) {
        cout << "Таким n быть не может" << endl;
        return 0;
    }
    else {
        n = n_double;   
    }
    cout << "Введите натуральное число x: ";
    cin >> x_double;
    if (x_double <= 0) {
        cout << "Таким Х быть не может" << endl;
        return 0;
    }
    else if (x_double != round(x_double)) {
        cout << "Введено дробное число. Программа не будет работать" << endl;
        return 0;
    }
    else {
        x = x_double;  
    }   
    cout << "Количество положительных делителей числа " << n << " равно " << dnx(n, x) << endl;
    return 0;
}