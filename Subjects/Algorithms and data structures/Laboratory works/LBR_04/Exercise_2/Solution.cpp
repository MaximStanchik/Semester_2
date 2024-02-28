//�������: � ���� ��������� "���-�����" ���������� ��������� �����. ������ ������ ����� � ���������. �����������, �������� ���� �������� ��������� ������ � ����� �������, ����� ������� ������� ��� ����� ������ �����.

//��� ���� �������: �� ������ ������� ���������� ������������ ����� � ����


//����: ����������� ����� �������(N < 10000) � ����� N ����������� ����� � ���� �������.���� ������ �������������(��������, �� 1 �� 100).
//����� : ������� ���������� �� ����� � ����� � ������������ ����� ����.








#include<iostream>
#include <algorithm>
#include <cstdlib> // ��� ������� rand()
#include <ctime> // ��� ������� time()

void sortEverySecond(int arr[], int n);
void toSum(int arr[], int n);
void toGenerateNumbers(int arr[], int n);


int main() {
    setlocale(LC_ALL, "Russian");
    int k=0;
    int n;
    int first=0;
    int sum = 0;
    int ubyt = 0;
    std::cout << "������� ����������� ����� �������(N < 10000)" << std::endl;
    std::cin >> n;
    int* arr = new int[n];
    
    

    if (n >= 10000) {
        std::cout << "�� ����� ������������ ���-�� ������� (� ��� N ������ ��� ����� 10000)" << std::endl;
        std::cout << "��������� �������� ���� ����������" << std::endl;
    }
    else if (n < 0) {
        std::cout << "�� ����� ������������ ���-�� ������� (� ��� N ������ 0)" << std::endl;
        std::cout << "��������� �������� ���� ����������" << std::endl;
    }
    else if (n < 10000 && n>0) {
        std::cout << "1--������ ���� �� ������ ��������������" << std::endl;
        std::cout << "2--������������� ��������� ���� �� ������" << std::endl;
        std::cout << "����� ������ �������--����� �� ���������" << std::endl;
    }
    std::cin >> k;
        switch (k) {
        case 1:
            
            for (int i = 0; i < n; i++) {		//��������� ���� �������
                arr[i] = rand() % 100 + 1;
                std::cout << arr[i] << " ";
                sum += arr[i];
            }
            std::cout << std::endl << std::endl;
            std::cout << "����� �������: " << sum << std::endl << std::endl;

            for (int i = 0; i < n; i++) {		//���������� �������
                for (int j = 0; j < n - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        int b = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = b;

                    }
                }
            }

            std::cout << "������������������ �������� ��������: " << std::endl;
            int i = 0;
            int j = n - 1;
            while (j > i) {
                std::cout << arr[j] << " ";
                std::cout << arr[i] << " ";
                ubyt += arr[i];
                i++; j--;
            }
            if (n % 2 != 0) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl << std::endl << "������ �������� ����������: " << ubyt << std::endl;
        



            break;
        case 2:
            
           
            for (int i = 0; i < n; i++) {		//��������� ���� �������
                arr[i] = rand() % 100 + 1;
                std::cout << arr[i] << " ";
                sum += arr[i];
            }
            std::cout << std::endl << std::endl;
            std::cout << "����� �������: " << sum << std::endl << std::endl;

            for (int i = 0; i < n; i++) {		//���������� �������
                for (int j = 0; j < n - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        int b = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = b;

                    }
                }
            }

            std::cout << "������������������ �������� ��������: " << std::endl;
            int i = 0;
            int j = n - 1;
            while (j > i) {
                std::cout << arr[j] << " ";
                std::cout << arr[i] << " ";
                ubyt += arr[i];
                i++; j--;
            }
            if (n % 2 != 0) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl << std::endl << "������ �������� ����������: " << ubyt << std::endl;
}

            break;
        }

        std::cout << "��������� ��������� ���� ����������" << std::endl;
        return 0;
    }
    
//
//void sortEverySecond(int arr[], int n) {
//    // ��������� ���� ������ �� �����������
//    std::sort(arr, arr + n);
//
//    // ������ ������� ������ ���� �����, ������� �� �������
//    for (int i = 1; i < n - 1; i += 2) {
//        std::swap(arr[i], arr[i + 1]);
//    }
//}
//
//
//
//void toGenerateNumbers(int arr[], int n) {
//    for (int i = 0; i < n; ++i)
//        std::cout << arr[i] << " ";
//    std::cout << std::endl;
//}