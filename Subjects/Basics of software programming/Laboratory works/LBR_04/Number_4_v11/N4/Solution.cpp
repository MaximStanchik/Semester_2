


                        //Вариант 11
                         //Условие:
//разработать программу для данных, приведенных в таблице ниже.
//Определить структурированный тип, разработать меню для работы с массивом структур.
//В программу должны войти функции:
//     --ввод элементов структуры с клавиатуры;
//     --вывод элементов структуры в консольное окно;
//	   --удаление заданной структурированной переменной;
//	   --поиск информации;
//	   --запись информации в файл;
//     --чтение данных из файла.

//Записная книжка.Ф.И.О, дата рождения, адрес, телефон, место работы или учебы, должность.Автоматическое формирование поздравления с днем рождения(по текущей дате).



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
    cout << "Здравствуйте, введите пожалуйста количество людей, которых вы хотите записать в записную книжку" << endl;
    cin >> size;
    for (i = 0; i < size; i++) {
        cout << i + 1 << "-ый человек " << endl;
        cout << "Введите Ф.И.О "<< endl;
        cin >> a[i].FULLNAME;
        cout << "Введите дату рождения" << endl;
        cin >> a[i].birthday;
        cout << "Введите адрес" << endl;
        cin >> a[i].adress;
        cout << "Введите телефон" << endl;
        cin >> a[i].phoneNumber;
        cout << "Введите место работы или учебы" << endl;
        cin >> a[i].workPlace;
        cout << "Введите должность" << endl;
        cin >> a[i].position;


    }

    return 0;
}






