



//Задание: В соответствии со своим вариантом разработать программу с использованием перечислений и битовых полей для работы с данными из таблицы, приведенной ниже. Реализовать функции ввода с клавиатуры, вывода на экран, удаления, поиска элементов. Интерфейс пользователя осуществить в виде меню.

//Условие: Ломбард. Фамилия клиента, наименование товара, оценочная стоимость, сумма, выданная под залог, дата сдачи, срок хранения. Выбор товаров по истечении срока хранения. Дату сдачи реализовать с помощью битового поля.



#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>


#define str_length 30
#define size 30
using namespace std;


int today_day = 19;
int today_montch = 5;
int today_year = 2023;

struct Product {
	int day : 5; // 5 бит для хранения дня (максимальное значение 31)
	int month: 5;
	int year : 12; // 12 битов для хранения года (максимальное значение 4095)
}production;


int month;
int choice;



struct Person {
	char place_of_work[str_length];
	float job_function;
	char factory_number[17];     // composed of 17 characters;
	float adress;
	char day_of_birthday;
	char name[str_length];
	float Best_before;
	int month;
	int day;
	int year;
};

struct Person list_of_persons[size];
struct Person empty_person;
int current_size = 0;

void enter_new(Product& product) {
	
	int count = 0;
	int days{};
	cout << "Ввод информации" << endl;
	if (current_size < size) {
		cout << "Номер строки " << current_size + 1 << endl;

		cout << "Фамилия клиента: ";
		cin.get();
		cin.getline(list_of_persons[current_size].name, 80);

		cout << "Наименование товара: ";
		cin.get();
		cin.getline(list_of_persons[current_size].place_of_work, 80);

		/*char a;
		getline(cin,a);
		list_of_persons[current_size].place_of_work = stoi(a);*/

		cout << "Оценочная стоимость: ";
		cin >> list_of_persons[current_size].adress;

		cout << "Сумма, выданная под залог: ";
		cin >> list_of_persons[current_size].job_function;

		cout << "Срок хранения (в днях): ";
		cin >> list_of_persons[current_size].Best_before;
		

		std::cout << "Введите дату сдачи товара (день месяца месяц год): ";
		int day,month, year;
		std::cin >> day >> month >> year;

		if (month == 01 && day > 31) {
			cout << "Вы ввели слишком большое значение (в январе 31 день)" << endl;
			exit(0);
		}
		if (month == 02 && year % 4 != 0 && day > 28) {
			cout << "Вы ввели слишком большое значение (в феврале в невисокосном году 28 дней)" << endl;
			exit(0);
		}
		if (month == 02 && year % 4 == 0 && day > 29) {
			cout << "Вы ввели слишком большое значение (в феврале в високосном году 29 дней)" << endl;
			exit(0);
		}
		if (month == 03 && day > 31) {
			cout << "Вы ввели слишком большое значение (в марте 31 день)" << endl;
			exit(0);
		}
		if (month == 04 && day > 30) {
			cout << "Вы ввели слишком большое значение (в апреле 30 дней)" << endl;
			exit(0);
		}
		if (month == 05 && day > 31) {
			cout << "Вы ввели слишком большое значение (в мае 31 день)" << endl;
			exit(0);
		}
		if (month == 06 && day > 30) {
			cout << "Вы ввели слишком большое значение (в июне 30 дней)" << endl;
			exit(0);
		}
		if (month == 07 && day > 31) {
			cout << "Вы ввели слишком большое значение (в июле 31 день)" << endl;
			exit(0);
		}
		if (month == 8 && day > 31) {
			cout << "Вы ввели слишком большое значение (в августе 31 день)" << endl;
			exit(0);
		}
		if (month == 9 && day > 30) {
			cout << "Вы ввели слишком большое значение (в сентябре 30 дней)" << endl;
			exit(0);
		}
		if (month == 10 && day > 31) {
			cout << "Вы ввели слишком большое значение (в октябре 31 день)" << endl;
			exit(0);
		}
		if (month == 11 && day > 30) {
			cout << "Вы ввели слишком большое значение (в ноябре 30 дней)" << endl;
			exit(0);
		}
		if (month == 12 && day > 31) {
			cout << "Вы ввели слишком большое значение (в декабре 31 день)" << endl;
			exit(0);
		}

		if (month > 12) {
			cout << "Неверный формат месяца, а именно:месяц больше 12";
			exit(0);
		}
		if (month < 1) {
			cout << "Неверный формат месяца, а именно:месяц меньше 1";
			exit(0);
		}

		list_of_persons[current_size].day = day;
		list_of_persons[current_size].year = year;
		list_of_persons[current_size].month = month;
		current_size++;
	}
	else
		cout << "Никакая дополнительная строка не может быть введена" << endl;
}

void del() {

	int str_number;
	cout << "Всего записей: " << current_size << endl;
	cout << "Будьте внимательны при вводе номера записи" << endl;
	cout << "Введите номер строки для удаления (введите 0, чтобы очистить все)" << endl;
	cin >> str_number;
	if (str_number > current_size) {
		cout << "Вы ввели номер несуществующей строки." << endl;
		cout << "Программа закончит свое выполнение." << endl;
		exit(0);
	}
    if (str_number != 0) {
		for (int de = (str_number - 1); de < current_size; de++)
			list_of_persons[de] = list_of_persons[de - 1];
		current_size -= 1;
	}
     if (str_number == 0)
		for (int i = 0; i < size; i++)
			list_of_persons[i] = empty_person;
}

void outputOneStructure(Person onePerson, const Product& product) {
	cout << "Фамилия клиента: " << onePerson.name << endl;
	cout << "Наименование товара: " << onePerson.place_of_work << endl;
	cout << "Оценочная стоимость: " << onePerson.adress << endl;
	cout << "Сумма, выданная под залог: " << onePerson.job_function << endl;
	cout << "Дата сдачи: " << onePerson.day << "." << onePerson.month << "." << onePerson.year << endl;
	cout << "Срок хранения: "<< onePerson.Best_before << endl;
}

void out() {
	int ch, num;
	cout << "1 - отображать одну запись" << endl;
	cout << "2 - отображать все запись" << endl;
	cin >> ch;
	if (ch == 1) {
		cout << "Введите номер строки для отображения" << endl;
		cin >> num;
		if (num > current_size or num < 1)
			cout << "Неверный ввод";
		cout << endl;
		num = num - 1;
		outputOneStructure(list_of_persons[num], production);
	}
	else if (ch == 2) {
		for (int i = 0; i < current_size; i++) {
			outputOneStructure(list_of_persons[i], production);
			cout << endl;
		}
	}
	else
		cout << "Неверный ввод";
}


void search() {
	float shelf_life;
	cout << "Введите срок хранения (кол-во дней)" << endl;
	cin >> shelf_life;
	cout << endl;
	for (int i = 0; i < current_size; i++) {
		if (list_of_persons[i].Best_before==shelf_life) {
			outputOneStructure(list_of_persons[i], production);
		}
	}
}


int main() {
	setlocale(LC_CTYPE, "Russian");
	cout << "Нет информации" << endl;
	do {
		cout << "Ввод:" << endl;
		cout << "1 - сделать новую запись" << endl;
		cout << "2 - удалить запись" << endl;
		cout << "3 - отобразить записи" << endl;
		cout << "4 - выбор товаров по истечении срока хранения" << endl;
		cout << "5 - выход" << endl;
		cin >> choice;
		switch (choice) {
		case 1: enter_new(production); break;
		case 2: del(); break;
		case 3: out(); break;
		case 4: search(); break;
		}
	} while (choice != 5);


}









	