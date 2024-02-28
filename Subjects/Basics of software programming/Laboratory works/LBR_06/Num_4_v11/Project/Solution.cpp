//В соответствии со своим вариантом разработать программу с использованием односвязного списка по данным, представленным в таблице ниже.
//Программа должна содержать меню с пунктами : добавление элемента, удаление элемента, поиск элемента, вывод списка в консольное окно, запись списка в файл, считывание списка из файла.

//Создать список, содержащий символы.Найти символ, равный введенному с клавиатуры, вывести этот символ и предыдущий.



#include "stdafx.h"
using namespace std;


void toAddAnEllement(Singly_linked_list*);

int main() {
    Singly_linked_list* head=NULL;
    setlocale(LC_CTYPE, "rus");
    int choice;
    do {
        cout << "1. Добавить элемент" << endl;
        cout << "2. Удалить элемент" << endl;
        cout << "3. Найти элемент" << endl;
        cout << "4. Вывести список" << endl;
        cout << "5. Сохранить список в файл  " << endl;
        cout << "6. Считать список из файла" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
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
            cout << "Неверный выбор. Попробуйте снова." << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}







