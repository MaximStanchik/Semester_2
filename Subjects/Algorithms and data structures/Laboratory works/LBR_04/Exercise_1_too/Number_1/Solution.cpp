#include<iostream>
#include<ctime>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int N; int sum = 0;
	cout << "������� ����� �������: ";
	cin >> N;
	if (N >= 10000) {
		std::cout << "�� ����� ������������ ���-�� ������� (� ��� N ������ ��� ����� 10000)" << std::endl;
		std::cout << "��������� �������� ���� ����������" << std::endl;
		return 0;
	}
	else if (N < 0) {
		std::cout << "�� ����� ������������ ���-�� ������� (� ��� N ������ 0)" << std::endl;
		std::cout << "��������� �������� ���� ����������" << std::endl;
		return 0;
	}
	else if (N < 10000 && N>0) {


		int* a = new int[N];


		for (int i = 0; i < N; i++) {		//��������� ���� �������
			a[i] = rand() % 100 + 1;
			cout << a[i] << " ";
			sum += a[i];
		}
		cout << endl << endl;
		cout << "������������ ����� � ����: " << sum << endl << endl;

		for (int i = 0; i < N; i++) {		//���������� �������
			for (int j = 0; j < N - 1; j++) {
				if (a[j] > a[j + 1]) {
					int b = a[j];
					a[j] = a[j + 1];
					a[j + 1] = b;

				}
			}
		}

		cout << "������������������ �������� ��������: " << endl;
		int i = 0;
		int j = N - 1;
		while (j > i) {
			cout << a[j] << " ";
			cout << a[i] << " ";
			i++; j--;
		}
		if (N % 2 != 0) {
			cout << a[i] << " ";
		}
	}

}