


                        //������� 11
                         //�������:
//����������� ��������� ��� ������, ����������� � ������� ����.
//���������� ����������������� ���, ����������� ���� ��� ������ � �������� ��������.
//� ��������� ������ ����� �������:
//     --���� ��������� ��������� � ����������;
//     --����� ��������� ��������� � ���������� ����;
//	   --�������� �������� ����������������� ����������;
//	   --����� ����������;
//	   --������ ���������� � ����;
//     --������ ������ �� �����.

//�������� ������.�.�.�, ���� ��������, �����, �������, ����� ������ ��� �����, ���������.�������������� ������������ ������������ � ���� ��������(�� ������� ����).



#include <iostream>
#include "stdafx.h"
#include <ctime>
#include <string>
using namespace std;



struct Person
{
    char FULLNAME[30];
    char birthday[30];
    char position[30];
    char adress[30];
    char phoneNumber[30];
    char workPlace[30];
    int year;
};




int main()
{
    setlocale(LC_ALL, "Russian");
    int size, i;
    int DATA = stoi(currentDateTime());
    cout << "������������, ������� ���������� ���������� �����, ������� �� ������ �������� � �������� ������" << endl;
    cin >> size;
    for (i = 0; i < size; i++) {
        cout << i + 1 << "-�� ������� " << endl;
        cout << "������� �.�.� "<< endl;
        cin >> a[i].FULLNAME;
        cout << "������� ���� ��������" << endl;
        cin >> a[i].birthday;
        cout << "������� �����" << endl;
        cin >> a[i].adress;
        cout << "������� �������" << endl;
        cin >> a[i].phoneNumber;
        cout << "������� ����� ������ ��� �����" << endl;
        cin >> a[i].workPlace;
        cout << "������� ���������" << endl;
        cin >> a[i].position;


    }

    return 0;
}






