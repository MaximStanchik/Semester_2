//� ������������ �� ����� ��������� ����������� ��������� � �������������� ������������ ������ �� ������, �������������� � ������� ����.
//��������� ������ ��������� ���� � �������� : ���������� ��������, �������� ��������, ����� ��������, ����� ������ � ���������� ����, ������ ������ � ����, ���������� ������ �� �����.

//������� ������, ���������� �������.����� ������, ������ ���������� � ����������, ������� ���� ������ � ����������.



#include "stdafx.h"
using namespace std;


void toAddAnEllement(Singly_linked_list*);

int main() {
    Singly_linked_list* head=NULL;
    setlocale(LC_CTYPE, "rus");
    int choice;
    do {
        cout << "1. �������� �������" << endl;
        cout << "2. ������� �������" << endl;
        cout << "3. ����� �������" << endl;
        cout << "4. ������� ������" << endl;
        cout << "5. ��������� ������ � ����  " << endl;
        cout << "6. ������� ������ �� �����" << endl;
        cout << "0. �����" << endl;
        cout << "�������� ��������: ";
        cin >> choice;
        switch (choice) {
        case 1:
            toAddAnEllement(head);
            break;
        case 2:
            break;

        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 0:
            break;
        default:
            cout << "�������� �����. ���������� �����." << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}







