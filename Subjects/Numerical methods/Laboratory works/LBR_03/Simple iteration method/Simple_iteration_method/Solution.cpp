//������� 24
//x^3+8*x-6=0
//�������� 0.01
//x=0.625
//a=0
//b=1
                                                               //�������:
                                      //���������� ����� ��������� ���������� � �������� ���� �� ��� ���-
                                      //���������� ��������(������� ������� ������� �������, ������� ��� -
                                      //����, ������� ������� ��������) � ��������� 0,01:



#include <iostream>
#include <cmath>
#include <iomanip> //����������� ��� ���� �����

using namespace std;

double eps = 0.01;

double f(double x)
{
    return x * x * x + 8 * x - 6;
}

double N(double x) {
    return (x * x * x * (-1) + 6)/8;
}

double df_1(double x) { // ������ ����������� �������
    return 3 * x * x + 8;
}

int main() {
    setlocale(LC_ALL, "Russian");
    double M;
    double x;
    cout << "������� ��������� ����������� �����" << endl;
    cin >> x;
    /*M = 1.01 * df_1(x);
    if (N(x) == (x - f(x)) / M) {*/
    while (abs(f(x)) > eps) {
        x = N(x);
    }
    cout << "��������������� �������� �����: " << x << endl;
    return 0;
}