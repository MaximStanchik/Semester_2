


//Задание: В соответствии со своим вариантом разработать программу с использованием структуры в виде объединения, для работы с данными из таблицы, приведенной ниже. Реализовать функции ввода с клавиатуры, вывода на экран и поиска. 

//Условие: Справочник автомобилей. Марка автомобиля, цвет, заводской номер, дата выпуска, тип кузова (седан, универсал и т. п.), дата последнего техосмотра, владелец. Выбор транспортных средств по владельцу.





#include <iostream>
#include <fstream>
#include <string>
#define str_length 30
#define size 30
using namespace std;


int choice;
int current_year = 2023;
int current_y = 2023;
int current_m = 4;
int current_d = 22;

struct Automobile {
	char Factory_number[17];
	char car_brand[str_length];
	char car_color[str_length];
	char body_type[str_length];
	int last_inspection_date;
	char owner[str_length];
	int Release_year;
};
union Auto {
	int release_data;
	int factory_number;     
};

struct Automobile list_of_cars[size];
struct Automobile empty_car;
int current_size = 0;

void enter_new() {
	Auto data;
	cout << "Information Entry" << endl;
	if (current_size < size) {
		cout << "Line number " << current_size + 1 << endl;

		cout << "Brand of the car: ";
		cin.get();
		cin.getline(list_of_cars[current_size].car_brand, 75);
		

		cout << "Car's color: ";
		cin.get();
		cin.getline(list_of_cars[current_size].car_color, 75);
		

		cout << "Factory number: ";
		cin.get();
		cin.getline(list_of_cars[current_size].Factory_number, 17);

		bool is_correct_year = false;
		do {
			cout << "Date of the car's release: ";
			cin>>data.release_data;
			int count = 0;
			int day = data.release_data / 1000000; //потому что переменная содержит восемь цифр и шесть цифр у нас отсекается у даты. получаем просто день. 
			int month = (data.release_data % 1000000) / 10000;
			int year = data.release_data % 10000;
			//тут цикл считает правильное кол-ко цифр вписано или нет. Если их мало или слишком много программа закрывается.

			


		
			list_of_cars[current_size].Release_year = data.release_data;
			if (data.release_data % 10000 <= current_year)
				is_correct_year = true;
			else
				cout << "Incorrect input" << endl;

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


		} while (is_correct_year == false);

		cout << "Body type: ";
		cin.get();
		cin.getline(list_of_cars[current_size].body_type, 75);
		

		int is_correct_inspection_date = 0;
		do {
			string temp_str_y;
			cout << "Last_inspection_date(DDMMYYYY): ";
			cin >> list_of_cars[current_size].last_inspection_date;

			int day, month, year;
			year = list_of_cars[current_size].last_inspection_date % 10000;
			month = (list_of_cars[current_size].last_inspection_date % 1000000 - year) / 10000;
			day = list_of_cars[current_size].last_inspection_date / 1000000;

			if (year == current_y)
				is_correct_inspection_date = 2;
			if (year < current_y)
				is_correct_inspection_date = 1;
			if (is_correct_inspection_date == 2) {
				if (month > current_m)
					is_correct_inspection_date = 0;
				else if (month == current_m)
					is_correct_inspection_date = 2;
				else if (month < current_m)
					is_correct_inspection_date = 1;
				else if (month > 12)
					is_correct_inspection_date = 0;
			}
			if (is_correct_inspection_date == 2) {
				if (day > current_d)
					is_correct_inspection_date = 0;
				else if (day <= current_d)
					is_correct_inspection_date = 1;
				else if (day > 31)
					is_correct_inspection_date = 0;
			}
			if (month > 12 or day > 31)
				is_correct_inspection_date = 0;
			if (is_correct_inspection_date == 0)
				cout << "Incorrect input" << endl;
		} while (is_correct_inspection_date == 0);

		cout << "Owner: ";
		cin.get();
		cin.getline(list_of_cars[current_size].owner, str_length);
		current_size++;
	}
	else
		cout << "No any more line can be entered" << endl;
}



void outputOneStructure(Automobile oneCar) {

	cout << "Brand of the car: " << oneCar.car_brand << endl;
	cout << "Car's color: " << oneCar.car_color << endl;
	cout << "Factory number: " << oneCar.Factory_number << endl;
	cout << "Date of realise: " << oneCar.Release_year << endl;
	cout << "Body type: " << oneCar.body_type << endl;
	cout << "Last_inspection_date(DDMMYYYY): " << oneCar.last_inspection_date << endl;
	cout << "Owner: " << oneCar.owner << endl;
}

void out() {
	int ch, num;
	cout << "1 - отображать одну запись" << endl;
	cout << "2 - отображать все записи" << endl;
	cin >> ch;
	if (ch == 1) {
		cout << "Введите номер строки для отображения" << endl;
		cin >> num;
		if (num > current_size or num < 1)
			cout << "Неверный ввод" << endl;
		exit(0);
		outputOneStructure(list_of_cars[num - 1]);
	}
	else if (ch == 2) {
		for (int i = 0; i < current_size; i++) {
			outputOneStructure(list_of_cars[i]);
			cout << endl;
		}
	}
	
	else
		cout << "Неверный ввод";
}





void search() {
	char the_owner[str_length];
	cout << "Enter the name of the owner" << endl;
	cin.get();
	cin.getline(the_owner, str_length);
	cout << endl;
	for (int i = 0; i < current_size; i++) {
		if (strcmp(list_of_cars[i].owner, the_owner) == 0) {
			outputOneStructure(list_of_cars[i]);
		}
	}
}




int main() {
	setlocale(LC_CTYPE, "Russian");
	cout << "No information" << endl;
	do {
		cout << "Enter:" << endl;
		cout << "1 - to make new record" << endl;
		cout << "2 - to display records" << endl;
		cout << "3 - to searh by the owner" << endl;
		cout << "4 - to exit" << endl;
		cin >> choice;
		switch (choice) {
		case 1: enter_new(); break;
		case 2: out(); break;
		case 3: search(); break;
		}
	} while (choice != 4);
}