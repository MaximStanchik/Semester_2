//������� 24





#include<iostream> // ��������� ������� ��� ����� � ������ �� �����
#include <math.h> // ��������� �������������� �������
#include <conio.h> //����������� ����� ���������� ������� � �++ ������� ����� ������ �������� ���� �� ����� ����� ����� ������ ����� ���� � �������������
double fxa(double x) {
	return ((pow(sqrt(log(x) * log(x)), 1 / 3) - 3 * log(2 * x) + 5) / 5 * x);
}
double fxb(double x) {
	return (sin(x) / pow(x, 3));
}

int main(){
	setlocale(LC_ALL, "Russian");
	double Integral; // ����� ����� ��������
	double a = 3, b = 7; // ����� ������� ��������������
	int h1 = 10, h2 = 100;// ����� ��� ��������������. h1--����� ������� ������� �� 10, h2--����� ������� ����� �� 100
	double n1, n2, n; // ����� ����� ��������� n
	int h, k, i, l, H;
	n1 = (b - a) / h1; 
	n2 = (b - a) / h2;
	std::cout << "������� ���������� ��������� ��������: " << std::endl;
	std::cout << "1--���� �� ������ ��������� ��������� �) � �) � ����� �������������� h1=10" << std::endl;
	std::cout << "2--���� �� ������ ��������� ��������� �) � �) � ����� �������������� h2=100" << std::endl;
	std::cout << "������� ����� ������ �������--���� �� ������ ����� �� ���������" << std::endl;
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
		std::cout << "���������� �� ������������� ������ ����������" << std::endl;
		return 0;
	}
	/*double A;
	double B;
	std::cout << "������� ������ �������� ��������� �)" << std::endl;
	std::cin >> A;
	std::cout << "������� ������ �������� ��������� b)" << std::endl;
	std::cin >> B;*/
	std::cout << "���������� ���������� �� ������� ��������:" << std::endl;

	Integral = h * (fxa(a) + fxa(b)) / 6.0;
	for (i = 1; i <= n; i++)
		Integral = Integral + 4.0 / 6.0 * h * fxa(a + h * (i - 0.5)); //��������� ������ �������� ��� ����� 
	for (i = 1; i <= n - 1; i++)
		Integral = Integral + 2.0 / 6.0 * h * fxa(a + h * i);
	std::cout << "����������� ��������� a) = " << Integral << "\n";
	/*double absolute_error_fxa_trapecia = A - Integral;*/
	/*std::cout << "���������� ����������� ������� ���������: " << absolute_error_fxa_trapecia << std::endl;
	double relative_error_fxa = std::abs((A - Integral) / A) * 100;
	std::cout << "������������� ����������� ������� ���������: " << relative_error_fxa << "%" << std::endl;*/
	Integral = 0;

	Integral = h * (fxb(a) + fxb(b)) / 6.0;
	for (l = 1; l <= n; l++)
		Integral = Integral + 4.0 / 6.0 * h * fxb(a + h * (l - 0.5));
	for (l = 1; l <= n - 1; l++)
		Integral = Integral + 2.0 / 6.0 * h * fxb(a + h * l);
	std::cout << "����������� ��������� b) = " << Integral << "\n";
	/*double absolute_error_fxb_trapecia = B - Integral;
	std::cout <<"���������� ����������� ������� ���������: " << absolute_error_fxb_trapecia << std::endl;
	relative_error_fxa = std::abs((B - Integral) / B) * 100;
	std::cout << "������������� ����������� ������� ���������: " << relative_error_fxa << "%" << std::endl;*/

	Integral = 0;

	std::cout << "���������� ���������� �� ������� ��������:" << std::endl;

	Integral = h * (fxa(a) + fxa(b)) / 2.0;
	for (i = 1; i <= n - 1; i++)
		Integral = Integral + h * fxa(a + h * i);
	Integral = Integral / 3;
	std::cout << "����������� ��������� a) = " << Integral << "\n";
	/*absolute_error_fxa_trapecia = A - Integral;
	std::cout << "���������� ����������� ������� ���������: " << absolute_error_fxa_trapecia << std::endl;
	relative_error_fxa = std::abs((A - Integral) / A) * 100;
	std::cout << "������������� ����������� ������� ���������: " << relative_error_fxa << "%" << std::endl;*/

	Integral = h * (fxb(a) + fxb(b)) / 2.0;
	for (i = 1; i <= n - 1; i++)
		Integral = Integral + h * fxb(a + h * i);
	Integral = Integral / 3;
	std::cout << "����������� ��������� b) = " << Integral << "\n";
	/*absolute_error_fxb_trapecia = B - Integral;
	std::cout << "���������� ����������� ������� ���������: " << absolute_error_fxb_trapecia << std::endl;
	relative_error_fxa = std::abs((B - Integral) / B) * 100;
	std::cout << "������������� ����������� ������� ���������: " << relative_error_fxa << "%" << std::endl;*/

	return 0;
}








