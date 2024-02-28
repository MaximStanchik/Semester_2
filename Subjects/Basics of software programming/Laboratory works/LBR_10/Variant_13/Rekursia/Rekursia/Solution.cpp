#include <iostream>
using namespace std;

int dnx(int n, int x) {
    if (x == 1) { // ������� ������
        return 1;
    }
    else if (n % x == 0 && x > 1) { // ���� x �������� ��������� n
        return dnx(n, x - 1) + 1;
    }
    else { // ���� x �� �������� ��������� n
        return dnx(n, x - 1);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    double n_double;
    int x;
    double x_double;
    cout << "������� ����������� ����� n: ";
    cin>> n_double;
    if (n_double != round(n_double)) {
        cout << "������� ������� �����. ��������� �� ����� ��������" << endl;
        return 0;
    }
    else if (n_double <= 0) {
        cout << "����� n ���� �� �����" << endl;
        return 0;
    }
    else {
        n = n_double;   
    }
    cout << "������� ����������� ����� x: ";
    cin >> x_double;
    if (x_double <= 0) {
        cout << "����� � ���� �� �����" << endl;
        return 0;
    }
    else if (x_double != round(x_double)) {
        cout << "������� ������� �����. ��������� �� ����� ��������" << endl;
        return 0;
    }
    else {
        x = x_double;  
    }   
    cout << "���������� ������������� ��������� ����� " << n << " ����� " << dnx(n, x) << endl;
    return 0;
}