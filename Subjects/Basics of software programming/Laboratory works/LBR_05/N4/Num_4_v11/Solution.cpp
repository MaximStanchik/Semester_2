



//�������: � ������������ �� ����� ��������� ����������� ��������� � �������������� ������������ � ������� ����� ��� ������ � ������� �� �������, ����������� ����. ����������� ������� ����� � ����������, ������ �� �����, ��������, ������ ���������. ��������� ������������ ����������� � ���� ����.

//�������: �������. ������� �������, ������������ ������, ��������� ���������, �����, �������� ��� �����, ���� �����, ���� ��������. ����� ������� �� ��������� ����� ��������. ���� ����� ����������� � ������� �������� ����.



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
	int day : 5; // 5 ��� ��� �������� ��� (������������ �������� 31)
	int month: 5;
	int year : 12; // 12 ����� ��� �������� ���� (������������ �������� 4095)
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
	cout << "���� ����������" << endl;
	if (current_size < size) {
		cout << "����� ������ " << current_size + 1 << endl;

		cout << "������� �������: ";
		cin.get();
		cin.getline(list_of_persons[current_size].name, 80);

		cout << "������������ ������: ";
		cin.get();
		cin.getline(list_of_persons[current_size].place_of_work, 80);

		/*char a;
		getline(cin,a);
		list_of_persons[current_size].place_of_work = stoi(a);*/

		cout << "��������� ���������: ";
		cin >> list_of_persons[current_size].adress;

		cout << "�����, �������� ��� �����: ";
		cin >> list_of_persons[current_size].job_function;

		cout << "���� �������� (� ����): ";
		cin >> list_of_persons[current_size].Best_before;
		

		std::cout << "������� ���� ����� ������ (���� ������ ����� ���): ";
		int day,month, year;
		std::cin >> day >> month >> year;

		if (month == 01 && day > 31) {
			cout << "�� ����� ������� ������� �������� (� ������ 31 ����)" << endl;
			exit(0);
		}
		if (month == 02 && year % 4 != 0 && day > 28) {
			cout << "�� ����� ������� ������� �������� (� ������� � ������������ ���� 28 ����)" << endl;
			exit(0);
		}
		if (month == 02 && year % 4 == 0 && day > 29) {
			cout << "�� ����� ������� ������� �������� (� ������� � ���������� ���� 29 ����)" << endl;
			exit(0);
		}
		if (month == 03 && day > 31) {
			cout << "�� ����� ������� ������� �������� (� ����� 31 ����)" << endl;
			exit(0);
		}
		if (month == 04 && day > 30) {
			cout << "�� ����� ������� ������� �������� (� ������ 30 ����)" << endl;
			exit(0);
		}
		if (month == 05 && day > 31) {
			cout << "�� ����� ������� ������� �������� (� ��� 31 ����)" << endl;
			exit(0);
		}
		if (month == 06 && day > 30) {
			cout << "�� ����� ������� ������� �������� (� ���� 30 ����)" << endl;
			exit(0);
		}
		if (month == 07 && day > 31) {
			cout << "�� ����� ������� ������� �������� (� ���� 31 ����)" << endl;
			exit(0);
		}
		if (month == 8 && day > 31) {
			cout << "�� ����� ������� ������� �������� (� ������� 31 ����)" << endl;
			exit(0);
		}
		if (month == 9 && day > 30) {
			cout << "�� ����� ������� ������� �������� (� �������� 30 ����)" << endl;
			exit(0);
		}
		if (month == 10 && day > 31) {
			cout << "�� ����� ������� ������� �������� (� ������� 31 ����)" << endl;
			exit(0);
		}
		if (month == 11 && day > 30) {
			cout << "�� ����� ������� ������� �������� (� ������ 30 ����)" << endl;
			exit(0);
		}
		if (month == 12 && day > 31) {
			cout << "�� ����� ������� ������� �������� (� ������� 31 ����)" << endl;
			exit(0);
		}

		if (month > 12) {
			cout << "�������� ������ ������, � ������:����� ������ 12";
			exit(0);
		}
		if (month < 1) {
			cout << "�������� ������ ������, � ������:����� ������ 1";
			exit(0);
		}

		list_of_persons[current_size].day = day;
		list_of_persons[current_size].year = year;
		list_of_persons[current_size].month = month;
		current_size++;
	}
	else
		cout << "������� �������������� ������ �� ����� ���� �������" << endl;
}

void del() {

	int str_number;
	cout << "����� �������: " << current_size << endl;
	cout << "������ ����������� ��� ����� ������ ������" << endl;
	cout << "������� ����� ������ ��� �������� (������� 0, ����� �������� ���)" << endl;
	cin >> str_number;
	if (str_number > current_size) {
		cout << "�� ����� ����� �������������� ������." << endl;
		cout << "��������� �������� ���� ����������." << endl;
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
	cout << "������� �������: " << onePerson.name << endl;
	cout << "������������ ������: " << onePerson.place_of_work << endl;
	cout << "��������� ���������: " << onePerson.adress << endl;
	cout << "�����, �������� ��� �����: " << onePerson.job_function << endl;
	cout << "���� �����: " << onePerson.day << "." << onePerson.month << "." << onePerson.year << endl;
	cout << "���� ��������: "<< onePerson.Best_before << endl;
}

void out() {
	int ch, num;
	cout << "1 - ���������� ���� ������" << endl;
	cout << "2 - ���������� ��� ������" << endl;
	cin >> ch;
	if (ch == 1) {
		cout << "������� ����� ������ ��� �����������" << endl;
		cin >> num;
		if (num > current_size or num < 1)
			cout << "�������� ����";
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
		cout << "�������� ����";
}


void search() {
	float shelf_life;
	cout << "������� ���� �������� (���-�� ����)" << endl;
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
	cout << "��� ����������" << endl;
	do {
		cout << "����:" << endl;
		cout << "1 - ������� ����� ������" << endl;
		cout << "2 - ������� ������" << endl;
		cout << "3 - ���������� ������" << endl;
		cout << "4 - ����� ������� �� ��������� ����� ��������" << endl;
		cout << "5 - �����" << endl;
		cin >> choice;
		switch (choice) {
		case 1: enter_new(production); break;
		case 2: del(); break;
		case 3: out(); break;
		case 4: search(); break;
		}
	} while (choice != 5);


}









	