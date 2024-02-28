

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




//����� ������� ������� �������:
#include <iostream>
#include <cmath>
#include <iomanip> 
using namespace std;

float eps = 0.01; 

double f(double x)
{
    return x * x * x + 8 * x - 6;
}

double bisection(double a, double b, float eps) { // ����� ������� ������� �������
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
    float a, b, A; //�--��� ������ ����� ���� �������� � � b �������
    double X; //X--��������� �������� �
    cout << "������� �������� �: ";
    cin >> a;
    cout << "������� �������� b: ";
    cin >> b;
    if (a > b) // ���� ���������� ������� �������, ������ �� �������
    {
        A = a;
        a = b;
        b = A;
    }
    cout << "������� ��������� �������� �: ";
    cin >> X;
    if (X > a && X < b) {
        double root = bisection(a, b, eps);
        cout << "������: " << root << endl;
    }
    else {
        cout << "�� ����� ������������ �������� ������� ��� �" << endl;
        cout << "��������� �������� ���� ����������" << endl;
        return 0;
    }
    return 0;
}


