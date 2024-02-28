#include"stdafx.h"
int Month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int NumberOfDay(int month, int days, int day, int year) {
	int numberofday = 0;
	if (year % 4 == 0) {
		Month[1] = 29;
	}

	for (int i = month - 2; i >= 0; i--)
	{
		days += Month[i];
	}
	numberofday = day + days;
	return numberofday;
	system("pause");
}