#include "stdafx.h"
using namespace std;


void toAddAnEllement(Singly_linked_list* structure_pointer) {
    char value;
    cout << "������� �������� ��������: ";
    while (true) { // ���������, ���� �� ����� ������� ���������� ��������
        cin >> value;

        if (cin.fail() || cin.peek() != '\n') { // ���� ������ ������������ ������
            cout << "������! ������� ���� �����: ";
            cin.clear(); // ������� ���� ������
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ���������� ��� ������� �� ����� ������
        }
        else { // ���� ��� ������� ���������
            break; // ������� �� �����
        }
    }
    Singly_linked_list* newNode = structure_pointer;
    while (newNode != NULL) {
        newNode = newNode->next;
    }
    newNode = new Singly_linked_list; //�������� ������ ������ � ��������� ��� ���� ������
    newNode->Symbol = value; //���������� ������ � ����� ����
    newNode->next = NULL; //��������� ������ �� ��������� ���� � ����� ����
}