#include "stdafx.h"
using namespace std;


void toAddAnEllement(Singly_linked_list* structure_pointer) {
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
    Singly_linked_list* newNode = structure_pointer;
    while (newNode != NULL) {
        newNode = newNode->next;
    }
    newNode = new Singly_linked_list; //Создание нового ячейки и выделение для него памяти
    newNode->Symbol = value; //Заполнение данных в новом узле
    newNode->next = NULL; //Установка ссылки на следующий узел в новом узле
}