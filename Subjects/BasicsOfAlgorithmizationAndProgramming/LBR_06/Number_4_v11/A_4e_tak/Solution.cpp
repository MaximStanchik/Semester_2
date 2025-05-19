#include <iostream>
#include <fstream>
#include <cctype> // для функции std::isdigit()
#include <cstdlib> // для функции std::exit()

using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev; // новое поле для хранения ссылки на предыдущий узел
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
    cout << "Введите значение элемента: ";
    while (true) { // повторяем, пока не будет введено корректное значение
        cin >> value;

        if (cin.fail() || cin.peek() != '\n') { // если введен некорректный символ
            cout << "Ошибка! Введите одну букву: ";
            cin.clear(); // очищаем флаг ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // игнорируем все символы до конца строки
        }
        else { // если все введено корректно
            break; // выходим из цикла
        }
    }
    Node* newNode = new Node; //Создание нового узла и выделение для него памяти
    newNode->data = value; //Заполнение данных в новом узле
    newNode->next = head; //Установка ссылки на следующий узел в новом узле
    newNode->prev = nullptr; // для первого элемента списка
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode; //Изменение ссылки на голову списка, чтобы она указывала на новый узел
}

void deleteNode() {
    char value;
    cout << "Введите значение элемента: ";
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
            cout << "Элемент удален." << endl;
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << "Элемент не найден." << endl;
}

void searchNode() {
    char value;
    cout << "Введите значение элемента: ";
    cin >> value;
    Node* current = head;
    Node* previous = nullptr; // добавляем переменную для хранения предыдущего узла
    while (current != nullptr) {
        if (current->data == value) {
            cout << "Элемент найден." << endl;
            cout << "Текущий элемент: " << current->data << endl;
            if (previous != nullptr) { // если предыдущий узел существует
                cout << "Предыдущий элемент: " << previous->data << endl;
            }
            else { // если текущий узел первый в списке
                cout << "Предыдущий элемент: -" << endl;
            }
            return;
        }
        previous = current; // сохраняем ссылку на предыдущий узел
        current = current->next;
    }
    cout << "Элемент не найден." << endl;
}

void saveList() {
    ofstream outFile("list.txt");
    Node* current = head;
    while (current != NULL) {
        outFile << current->data << endl;
        current = current->next;
    }
    outFile.close();
    cout << "Список сохранен в файле." << endl;
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
    cout << "Список загружен из файла." << endl;
}



int main() {
    setlocale(LC_CTYPE, "rus");
    int choice;
    do {
        cout << "1. Добавить элемент" << endl;
        cout << "2. Найти элемент" << endl;
        cout << "3. Удалить элемент" << endl;
        cout << "4. Вывести список" << endl;
        cout << "5. Сохранить список в файл  " << endl;
        cout << "6. Считать список из файла" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
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
            cout << "Неверный выбор. Попробуйте снова." << endl;
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