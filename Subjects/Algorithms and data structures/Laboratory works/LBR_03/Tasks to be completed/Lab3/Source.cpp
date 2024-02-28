#include<iostream>
#include<ctime>

using namespace std;

//��������� ��� ������� ������������
void toquickSort(int* array, int lowvalue, int highvalue)
{
	int i = lowvalue;//��� ����� ������ ������ ��������
	int j = highvalue;//��������� ��������
	int pivot = array[(i + j) / 2];//����������� ������� �������
	int temp;

	while (i <= j)
	{
		while (array[i] < pivot)
			i++; //���������� � ����� �����
		while (array[j] > pivot)
			j--;//���������� � ������ �����
		if (i <= j) //�������� i � j �������� ������� ���� ����������� �������
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	}
	if (j > lowvalue) //���� ��������� �������� ������ ������� 
		toquickSort(array, lowvalue, j);
	if (i < highvalue)//���� ��������� �������� ������ ������� 
		toquickSort(array, i, highvalue);
}


int main()
{
	setlocale(LC_CTYPE, "russian");
	srand(time(NULL));
	int N;
	clock_t start, end; //clock_t �������� �������� �����, ��������� � ������� ������������� CRT ��� ������� ��������
	double cpu_time_used;
	cout << "����������,������� ������ �������: ";
	cin >> N;
	//��� �� �������� ������ � � ������� B, C, D, �.
	int* A = new int[N];
	int* B = new int[N];
	int* C = new int[N];
	int* D = new int[N];
	int* E = new int[N];

	cout << "�������� ������ A: " << endl;
	for (int i = 0; i < N; i++) {
		A[i] = rand(); //��� � ������� rand ������� ��������� �����
		cout << A[i] << " ";
	}

	cout << endl << endl;
	//��� �������� � ������ ������� ������ �[]
	for (int i = 0; i < N; i++) {
		B[i] = A[i];
		C[i] = A[i];
		D[i] = A[i];
		E[i] = A[i];
	}

	start = clock(); //��� �� �������� ������� ������� ������� ����� �� ���������� ����

	for (int i = 0; i < N; i++) { //���� ������ �� ����� �������� �� 5 ����� ��������� ����� �����������
		for (int j = 0; j < N - 1; j++) {
			if (B[j] > B[j + 1]) { //���� ����� ������� ������ �������, ��:
				int b = B[j]; //����� � ������ ������� �������� �������
				B[j] = B[j + 1];
				B[j + 1] = b;
			}
		}
	}
	cout << "��������������� ������ B ������� ����������� ����������: " << endl;
	for (int i = 0; i < N; i++) {//������� ��������������� �������� ������� N ��� �� �������
		cout << B[i] << " ";
	}
	cout << endl;

	end = clock();//��� ������������� ����������
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC; //CLOCKS_PER_SEC--������, ������������ �� ��������, �������������� ����� ����� � �������, ������� ���������� ������� clock.

	cout << "�����,����������� �� ���������� ����������: " << cpu_time_used << " ������" << endl;

	cout << endl;

	start = clock();

	int l, c;
	l = N / 2;//��� ����� ������ �� 2
	while (l != 0) {
		for (int i = 0; i < N - l; i++) {
			int j = i;
			while (j >= 0 && C[j] > C[j + l]) {
				c = C[j];
				C[j] = C[j + l];
				C[j + l] = c;//�������� �������� �������
				j--;
			}
		}
		l = l / 2; //� ���� �� ����� ������ �� 2 �� ������ �����
	}
	cout << "��������������� ������ C ����������� �������� (��� ������� �����): " << endl;
	for (int i = 0; i < N; i++) { //������� ��������������� �������� ������� N ��� �� �������
		cout << C[i] << " ";
	}
	cout << endl;

	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

	cout << "�����,����������� �� ���������� ����������: " << cpu_time_used << " ������" << endl;

	cout << endl;

	start = clock();

	int d;
	int min;//������� ����� ����� ������� � ������� � ����������� ���������
	for (int i = 0; i < N; i++) {
		min = i;
		for (int j = i + 1; j < N; j++) {
			if (D[j] < D[min]) {//����� ������������ 1 � 2  �������� �������, ����� 2 �3 � �.�.
				min = j;//����������� ��������=����� �������� �������
			}
		}
		if (i != min)
		{
			d = D[i]; //��� ���������� ������ ��������� �������
			D[i] = D[min];
			D[min] = d;
		}
	}
	cout << "��������������� ������ D ����������� ������: " << endl;
	for (int i = 0; i < N; i++) {//��� ������� �� ������� ���������������� �������� �������
		cout << D[i] << " ";
	}
	cout << endl;

	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

	cout << "�����,����������� �� ���������� ����������: " << cpu_time_used << " ������" << endl;

	cout << endl;

	start = clock(); //�������� ������ ������� ��� ������������ �������� ������� ����������� ���������

	toquickSort(E, 0, N - 1); //���������� ������� quickSort ��� ������� ����������
	cout << "��������������� ������ E ������� �����������:" << endl;
	for (int i = 0; i < N; i++) {//��� ��������� � ������� ������������� �������� �������
		cout << E[i] << " ";
	}
	cout << endl;

	end = clock();//��� ��� ����������
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

	cout << "�����,����������� �� ���������� ����������: " << cpu_time_used << " ������" << endl;
	
	
	//���������� delete ��� ������� new � ����� ���������� ������, ���������� ���������� new ������� � ���� ����� �������� ������ ������ (����--��� ��������� ������,�������������� � ���, ������� ��������� ��������� ������������ ������)
	delete[] A;
	delete[] B;
	delete[] C;
	delete[] D;
	delete[] E;
	
}