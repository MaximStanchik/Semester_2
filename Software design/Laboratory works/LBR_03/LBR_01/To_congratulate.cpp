#include"stdafx.h"
int numindays(int year) {
	int num, daynumber, day, month = 1;
	cout << "Введите порядковый номер дня, после чего будет выведено число и месяц, соответствующие порядковому номеру дня";
	cin >> num;
	daynumber = num;
	int Months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (num > 366) {
		cout << "Вы ввели число, большее 366. А так не бывает" << endl;
		cout << "Программа закончит свое выполнение." << endl; 
		cout << "Благодарим за пользование нашим приложением!" << endl;
		return 0;
	}
	
	if (num < 1) {
		cout << "Вы ввели отрицательное значение порядкового номера" << endl;
		cout << "Программа закончит свое выполнение." << endl;
		cout << "Благодарим за пользование нашим приложением!" << endl;
		return 0;
	}

	if (num == 366) {
		Months[1] = 29;
	}
	
	for (int i = 0; num > Months[i]; i++) {
		num = num - Months[i];
		month++;
	}
	day = num;
	cout << "Вы указали дату: " << day << "-ое "; monthName(month);;;


	if (daynumber == 256) {
		cout << "	С днем программиста!!! Программирование это круто!!!" << endl << endl;
		return 1;
	}

	if (day == 8 && month == 3) {
		cout << "	В этот долгожданный день празднуется Женский день." << endl << endl; 
		return 1;
	}
	if (day == 1 && month == 6) {
		cout << "	Ураааааааааааааа!!! Первый денб лета!" << endl << endl;
		return 1;
	}

	if (day == 1 && month == 1) {
		cout << "	С Новым годом! С новым счастьем!" << endl << endl;
		return 1;
	}

	if (daynumber == 216) {
		cout << "     С днем пива!!!" << endl << endl;
		return 1;
	}

	if (daynumber == 45) {
		cout << "      С днем Святого Валентина!!!" << endl << endl;
		return 1;
	}

	if (daynumber == 48) {
		cout << "      С днем спонтанного проявления доброты!!!" << endl << endl;
		return 1;
	}

	if (daynumber == 172) {
		cout << "      С селфи!!!" << endl << endl;
		return 1;
	}

	if (daynumber == 3) {
		cout << "      С днем рождения соломинки для коктейлей!!!" << endl << endl;
		return 1;
	}

	return 1;
}