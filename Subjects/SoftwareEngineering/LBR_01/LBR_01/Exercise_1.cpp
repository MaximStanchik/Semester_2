#include<iostream>
#include <ctime>
#include <string>
#include "stdafx.h"
//count--счетчик

using namespace std;

//тут у нас функция для подсчета текущей даты


int main() {
	setlocale(LC_CTYPE, "ru");
	int DATA = stoi(currentDateTime());
	int data, day, month, year,A, days{}, Birthday, YearOfBirthday, NumberOfcurrentDay, left;
	int count = 0;
	int Months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	cout << "Введите дату в формате 'ДДММГГГГ': ";
	cin >> data;

	day = data / 1000000; //потому что переменная содержит восемь цифр и шесть цифр у нас отсекается у даты. получаем просто день. 
	month = (data % 1000000) / 10000;
	year = data % 10000;

	

	//тут цикл считает правильное кол-ко цифр вписано или нет. Если их мало или слишком много программа закрывается.

	while (data > 0) {
		data /= 10; // /= значит разделить переменную на значение и ответ присвоить этой же переменной
		count++;
	}
	if (count < 7 && count > 8) {
		cout << "Неверное количество данных или в дату введенна цифра";
		exit(0);
	}

	//Тут определяем правильно ли введен день

	if (month == 01 && day > 31) {
		cout << "Вы ввели слишком большое значение (в январе 31 день)" << endl;
		return 0;
	}
	if (month == 02 && year % 4 != 0 && day > 28) {
		cout << "Вы ввели слишком большое значение (в феврале в невисокосном году 28 дней)" << endl;
		return 0;
	}
	if (month == 02 && year % 4 == 0 && day > 29) {
		cout << "Вы ввели слишком большое значение (в феврале в високосном году 29 дней)" << endl;
		return 0;
	}
	if (month == 03 && day > 31) {
		cout << "Вы ввели слишком большое значение (в марте 31 день)" << endl;
		return 0;
	}
	if (month == 04 && day > 30) {
		cout << "Вы ввели слишком большое значение (в апреле 30 дней)" << endl;
		return 0;
	}
	if (month == 05 && day > 31) {
		cout << "Вы ввели слишком большое значение (в мае 31 день)" << endl;
		return 0;
	}
	if (month == 06 && day > 30) {
		cout << "Вы ввели слишком большое значение (в июне 30 дней)" << endl;
		return 0;
	}
	if (month == 07 && day > 31) {
		cout << "Вы ввели слишком большое значение (в июле 31 день)" << endl;
		return 0;
	}
	if (month == 8 && day > 31) {
		cout << "Вы ввели слишком большое значение (в августе 31 день)" << endl;
		return 0;
	}
	if (month == 9 && day > 30) {
		cout << "Вы ввели слишком большое значение (в сентябре 30 дней)" << endl;
		return 0;
	}
	if (month == 10 && day > 31) {
		cout << "Вы ввели слишком большое значение (в октябре 31 день)" << endl;
		return 0;
	}
	if (month == 11 && day > 30) {
		cout << "Вы ввели слишком большое значение (в ноябре 30 дней)" << endl;
		return 0;
	}
	if (month == 12 && day > 31) {
		cout << "Вы ввели слишком большое значение (в декабре 31 день)" << endl;
		return 0;
	}

	//Тут определяем правильно ли введен месяц

	if (month > 12) {
		cout << "Неверный формат месяца, а именно:месяц больше 12";
		exit(0);
	}
	if (month < 1) {
		cout << "Неверный формат месяца, а именно:месяц меньше 1";
		exit(0);
	}


	//тут определяем правильно ли ввели год или нет
	if (year < 0) {
		cout << "Вы неправильно ввели год, а именно: год отрицательный" << endl;
		return 0;
	}

	//тут определяем год високосный или нет

	leapOrNot(year);


	//Тут мы считаем порядковый номер дня в году


	NumberOfDay(month, days, day, year);
	/*A= NumberOfDay(month, days, day, year);*/
	cout << "Порядковый номер дня: " << NumberOfDay(month, days, day, year)<< endl;
	days = 0;
	day = 0;




	//Тут мы вводим день рождения 
	cout << "Введите вашу ближайшую дату дня рождения 'ДДММГГГГ': ";
	cin >> data;

	day = data / 1000000; //потому что переменная содержит восемь цифр и шесть цифр у нас отсекается у даты. получаем просто день. 
	month = (data % 1000000) / 10000;
	year = data % 10000;

	

	//Если год високосный в феврале 29 дней
	if (year % 4 == 0) {
		Months[1] = 29;
	}


	//проверка правильности написания дней
	if (month == 01 && day > 31) {
		cout << "Вы ввели слишком большое значение (в январе 31 день)" << endl;
		return 0;
	}
	if (month == 02 && year % 4 != 0 && day > 28) {
		cout << "Вы ввели слишком большое значение (в феврале в невисокосном году 28 дней)" << endl;
		return 0;
	}
	if (month == 02 && year % 4 == 0 && day > 29) {
		cout << "Вы ввели слишком большое значение (в феврале в високосном году 29 дней)" << endl;
		return 0;
	}
	if (month == 03 && day > 31) {
		cout << "Вы ввели слишком большое значение (в марте 31 день)" << endl;
		return 0;
	}
	if (month == 04 && day > 30) {
		cout << "Вы ввели слишком большое значение (в апреле 30 дней)" << endl;
		return 0;
	}
	if (month == 05 && day > 31) {
		cout << "Вы ввели слишком большое значение (в мае 31 день)" << endl;
		return 0;
	}
	if (month == 06 && day > 30) {
		cout << "Вы ввели слишком большое значение (в июне 30 дней)" << endl;
		return 0;
	}
	if (month == 07 && day > 31) {
		cout << "Вы ввели слишком большое значение (в июле 31 день)" << endl;
		return 0;
	}
	if (month == 8 && day > 31) {
		cout << "Вы ввели слишком большое значение (в августе 31 день)" << endl;
		return 0;
	}
	if (month == 9 && day > 30) {
		cout << "Вы ввели слишком большое значение (в сентябре 30 дней)" << endl;
		return 0;
	}
	if (month == 10 && day > 31) {
		cout << "Вы ввели слишком большое значение (в октябре 31 день)" << endl;
		return 0;
	}
	if (month == 11 && day > 30) {
		cout << "Вы ввели слишком большое значение (в ноябре 30 дней)" << endl;
		return 0;
	}
	if (month == 12 && day > 31) {
		cout << "Вы ввели слишком большое значение (в декабре 31 день)" << endl;
		return 0;
	}
	
	//проверка кол-ва цифр (их должно быть 8)
	while (data > 0) {
		data /= 10; // /= значит разделить переменную на значение и ответ присвоить этой же переменной
		count++;
	}
	if (count < 7 && count > 8) {
		cout << "Неверное количество данных или в дату введенна цифра";
		exit(0);
	}
	//Тут определяем правильно ли введен месяц

	if (month > 12) {
		cout << "Неверный формат месяца, а именно:месяц больше 12";
		exit(0);
	}
	if (month < 1) {
		cout << "Неверный формат месяца, а именно:месяц меньше 1";
		exit(0);
	}


	////далее у нас подсчитывается текущая дата для того,чтобы потом вычислить сколько дней осталось до ближайшего дня рождения
	
	
	

	
	NumberOfDay(month, days, day, year);
	Birthday = NumberOfDay(month, days, day, year);
	days = 0;
	day = 0;
	YearOfBirthday = year;
	int MOUNTH = month;
	year = 0;
	month = 0;

	day = DATA / 1000000; //потому что переменная содержит восемь цифр и шесть цифр у нас отсекается у даты. получаем просто день. 
	month = (DATA % 1000000) / 10000;
	year = DATA % 10000;


	//Если год високосный в феврале 29 дней
	if (year % 4 == 0) {
		Months[1] = 29;
	}




	NumberOfDay(month, days, day, year);
	NumberOfcurrentDay = NumberOfDay(month, days, day, year);
	//cout << "Порядковый номер дня: " << numberofday << endl;
	days = 0;
	day = 0;



	//Высчитываем сколько дней осталось до дня рождения
	if (year == YearOfBirthday && Birthday>NumberOfcurrentDay) {
		left=Birthday-NumberOfcurrentDay;
		cout << "До вашего дня рождения осталось "<<left<<" дней"<< endl;	
	}
	else if (YearOfBirthday==year+1 && year % 4 == 0) {
		left = 366-NumberOfcurrentDay + Birthday;
		cout << "До вашего дня рождения осталось " << left << " дней" << endl;
	}
	else if (YearOfBirthday == year + 1 && year % 4 != 0) {
		left = 365 - NumberOfcurrentDay + Birthday;
		cout << "Вы ввели неправильно ближайшую дату рождения, а именно: Ваш ближайший день рождения будет в этом году."<< endl;
	}
	else if (YearOfBirthday<year) {
		cout << "Вы ввели неправильно ближайшую дату рождения, а именно: год ближайшего дня рождения меньше чем текущий год." << endl;
	}
	else if (YearOfBirthday > year + 1) {
		cout << "Вы ввели неправильно ближайшую дату рождения, а именно: ближайший день рождения через несколько лет?! ОГО! Нет, пожалуйста, введите дату правильно." << endl;
	}
	else if (year == YearOfBirthday && NumberOfcurrentDay > NumberOfcurrentDay && year % 4 == 0) {
		left =366- NumberOfcurrentDay+ Birthday;
		cout << "До вашего дня рождения осталось " << left << " дней"<< endl;
	}
	else if (year == YearOfBirthday && NumberOfcurrentDay > NumberOfcurrentDay && year % 4 != 0) {
		left = 365 - NumberOfcurrentDay + Birthday;
		cout << "До вашего дня рождения осталось " << left << " дней"<< endl;
	}
	else if (month >month && YearOfBirthday>year) {
		cout << "Вы неправильно ввели дату. Будьте внимательней." << endl;	
	}
	cout << "Программа закончила свое выполнение. Благодарим за использование нашего приложения" << endl;
	system("pause");
	return 0;
}




