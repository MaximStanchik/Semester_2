#include <iostream>
#include <fstream>
#include <cctype> // ��� ������� std::isdigit()
#include <cstdlib> // ��� ������� std::exit()

using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev; // ����� ���� ��� �������� ������ �� ���������� ����
};

Node* head = NULL;

void printList() {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void insertNode() {
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
    Node* newNode = new Node; //�������� ������ ���� � ��������� ��� ���� ������
    newNode->data = value; //���������� ������ � ����� ����
    newNode->next = head; //��������� ������ �� ��������� ���� � ����� ����
    newNode->prev = nullptr; // ��� ������� �������� ������
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode; //��������� ������ �� ������ ������, ����� ��� ��������� �� ����� ����
}

void deleteNode() {
    char value;
    cout << "������� �������� ��������: ";
    cin >> value;
    Node* current = head;
    Node* previous = NULL;
    while (current != NULL) {
        if (current->data == value) {
            if (previous == NULL) {
                head = current->next;
            }
            else {
                previous->next = current->next;
            }
            delete current;
            cout << "������� ������." << endl;
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << "������� �� ������." << endl;
}

void searchNode() {
    char value;
    cout << "������� �������� ��������: ";
    cin >> value;
    Node* current = head;
    Node* previous = nullptr; // ��������� ���������� ��� �������� ����������� ����
    while (current != nullptr) {
        if (current->data == value) {
            cout << "������� ������." << endl;
            cout << "������� �������: " << current->data << endl;
            if (previous != nullptr) { // ���� ���������� ���� ����������
                cout << "���������� �������: " << previous->data << endl;
            }
            else { // ���� ������� ���� ������ � ������
                cout << "���������� �������: -" << endl;
            }
            return;
        }
        previous = current; // ��������� ������ �� ���������� ����
        current = current->next;
    }
    cout << "������� �� ������." << endl;
}

void saveList() {
    ofstream outFile("list.txt");
    Node* current = head;
    while (current != NULL) {
        outFile << current->data << endl;
        current = current->next;
    }
    outFile.close();
    cout << "������ �������� � �����." << endl;
}
  
void clearList() {
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
}

void loadList() {
    clearList();
    ifstream inFile("list.txt");
    char value;
    char c;
    while (inFile >> c) {
            inFile.unget();
            inFile >> value;
            Node* newNode = new Node;
            newNode->data = value;
            newNode->next = head;
            head = newNode;
            cout << value << ' ';
    }
    cout << endl;
    inFile.close();
    cout << "������ �������� �� �����." << endl;
}



int main() {
    setlocale(LC_CTYPE, "rus");
    int choice;
    do {
        cout << "1. �������� �������" << endl;
        cout << "2. ����� �������" << endl;
        cout << "3. ������� �������" << endl;
        cout << "4. ������� ������" << endl;
        cout << "5. ��������� ������ � ����  " << endl;
        cout << "6. ������� ������ �� �����" << endl;
        cout << "0. �����" << endl;
        cout << "�������� ��������: ";
        cin >> choice;
        switch (choice) {
        case 1:
            insertNode();
            break;
        case 2:
            searchNode();
            break;

        case 3:
            deleteNode();
            break;
        case 4:
            printList();
            break;
        case 5:
            saveList();
            break;
        case 6:
            loadList();
            break;
        case 0:
            break;
        default:
            cout << "�������� �����. ���������� �����." << endl;
            break;
        }
    } while (choice != 0);

    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }
    head = NULL;

    return 0;
}