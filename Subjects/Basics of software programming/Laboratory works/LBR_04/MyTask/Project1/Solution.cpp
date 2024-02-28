

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

//Справочник автомобилей. Марка автомобиля, цвет, заводской номер, дата выпуска, тип кузова (седан,
//универсал и т. п.), дата последнего техосмотра, владелец. Выбор транспортных средств по владельцу.



/*В соответствии со своим вариантом разработать программу для данных, приведенных в таблице ниже. Определить
структурированный тип, разработать меню для работы с массивом структур.
В программу должны войти функции:
− ввод элементов структуры с клавиатуры;
− вывод элементов структуры в консольное окно;
− удаление заданной структурированной переменной;
− поиск информации;
− запись информации в файл;
− чтение данных из файла.

Справочник автомобилей. Марка автомобиля, цвет, заводской номер, дата выпуска, тип кузова (седан,
универсал и т. п.), дата последнего техосмотра, владелец. Выбор транспортных средств по владельцу.
*/
//Записная книжка. Ф.И.О, дата рождения, адрес, телефон, место работы или учебы, должность. Автоматическое формирование поздравления с днем рождения (по текущей дате). 

#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#define str_length 30
#define size 30
using namespace std;




int choice;
int current_year = 2023;
int current_y = 2023;
int current_m = 2;
int current_d = 14;

struct Person {
	char place_of_work[str_length];
	char job_function[str_length];
	char factory_number[17];     // composed of 17 characters;
	char adress[str_length];
	char day_of_birthday;
	char name[str_length];
};

struct Person list_of_persons[size];
struct Person empty_person;
int current_size = 0;

void enter_new() {
	int count = 0;
	cout << "Ввод информации" << endl;
	if (current_size < size) {
		cout << "Номер строки " << current_size + 1 << endl;

		cout << "Место работы/учебы: ";
		cin.get();
		cin.getline(list_of_persons[current_size].place_of_work, 75);
		cout << "Должность: ";
		cin.get();
		cin.getline(list_of_persons[current_size].job_function, 75);
		
		cout << "Адрес: ";
		cin.get();
		cin.getline(list_of_persons[current_size].adress, 75);


		
		string temp_str_y;
		cout << "Дата рождения (ДДММГГГГ): ";
		cin >> list_of_persons[current_size].day_of_birthday;

		int day, month, year;
		year = list_of_persons[current_size].day_of_birthday % 10000;
		month = (list_of_persons[current_size].day_of_birthday % 1000000 - year) / 10000;
		day = list_of_persons[current_size].day_of_birthday / 1000000;
		cout << "Ф.И.О: ";
		cin.get();
		cin.getline(list_of_persons[current_size].name, 75);
		current_size++;
	}
	else
		cout << "Никакая дополнительная строка не может быть введена" << endl;
}

void del() {

	int str_number;
	cout << "Введите номер строки для удаления (введите 0, чтобы очистить все)" << endl;
	cin >> str_number;
	if (str_number != 0) {
		for (int de = (str_number - 1); de < current_size; de++)
			list_of_persons[de] = list_of_persons[de - 1];
		current_size -= 1;
	}
	if (str_number == 0)
		for (int i = 0; i < size; i++)
			list_of_persons[i] = empty_person;
}

void outputOneStructure(Person onePerson) {
	cout << "Место работы/учебы: " << onePerson.place_of_work << endl;
	cout << "Должность: " << onePerson.job_function << endl;
	cout << "Адрес (вводить без пробелов): " << onePerson.adress << endl;
	cout << "Ближайшей день рождения (в формате ДДММГГГГ): " << onePerson.day_of_birthday << endl;
	cout << "Ф.И.О: " << onePerson.name << endl;
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
		outputOneStructure(list_of_persons[num - 1]);
	}
	else if (ch == 2) {
		for (int i = 0; i < current_size; i++) {
			outputOneStructure(list_of_persons[i]);
			cout << endl;
		}
	}
	else
		cout << "Неверный ввод";
}

void outToFile() {
	int N = 10;
	fflush(stdin); //clean the stream;
	ofstream file1("information.txt");
	for (int i = 0; i < current_size; i++) {
		file1 << "\tCar № " << i + 1 << endl;

		file1 << "Место работы/учебы: ";
		file1 << list_of_persons[i].place_of_work << endl;

		file1 << "Должность: ";
		file1 << list_of_persons[i].job_function << endl;


		file1 << "Адрес: ";
		file1 << list_of_persons[i].adress << endl;


		file1 << "Дата рождения (в формате ДДММГГГГ): ";
		file1 << list_of_persons[i].day_of_birthday << endl;

		file1 << "Ф.И.О: ";
		file1 << list_of_persons[i].name << endl << endl << endl;
	}
	cout << endl << endl;
}

void inputFromFile() {
	string str;
	ifstream file1("information.txt");
	while (file1) {
		getline(file1, str);
		cout << str << endl;
	}
}



//void birthday() {
//	time_t now = time(0); // получаем текущую дату и время
//	tm* ltm = localtime(&now); // преобразуем в структуру tm
//
//	string date; // строка для хранения даты из файла
//	string name; // строка для хранения имени из файла
//
//	ifstream file("information.txt"); // открываем файл для чтения
//
//	while (getline(file, name)) { // считываем построчно из файла
//		getline(file, date);
//		// остальные данные не будем использовать в данной задаче
//
//		// проверяем, совпадает ли дата из файла с текущей датой
//		if (date == to_string(ltm->tm_mday) + to_string(1 + ltm->tm_mon) + to_string(1900 + ltm->tm_year)) {
//			cout << "Сегодня день рождения у " << name << "!" << endl;
//			cout << "Поздравляем его (ее) с днем рождения!" << endl;
//			cout << "Желаем много счастья, здоровья и успехов во всех начинаниях!" << endl;
//			cout << endl; // пустая строка для разделения поздравлений
//		}
//	}
//}


//подсчет времени:
string currentDateTime() {
	time_t t = time(nullptr);
	tm* now = localtime(&t);
	char buffer[128];
	strftime(buffer, sizeof(buffer), "%d%m%Y", now);
	return buffer;
}

void search() {
	char the_owner[str_length];
	cout << "Enter the name of the owner" << endl;
	cin >> the_owner;
	cout << endl;
	for (int i = 0; i < current_size; i++) {
		if (strcmp(list_of_persons[i].name, the_owner) == 0) {
			outputOneStructure(list_of_persons[i]);
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
		cout << "4 - войти в файл" << endl;
		cout << "5 - отобразить информацию в файле" << endl;
		cout << "6-поздравить кого-нибудь с др" << endl;
		cout << "7 - выход" << endl;
		cin >> choice;
		switch (choice) {
		case 1: enter_new(); break;
		case 2: del(); break;
		case 3: out(); break;
		case 4: outToFile(); break;
		case 5: inputFromFile(); break;
		case 6: search(); break;
		}
	} while (choice != 7);


}