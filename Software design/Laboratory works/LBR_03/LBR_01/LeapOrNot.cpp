#include"stdafx.h"

bool leapOrNot(int year)
{
	//без условия
	if (year % 4 == 0) {
		cout <<"Год високосный"<< endl;
		return true;
		
	}
	else {
		cout << "Год не високосный" << endl;
		return false;
	}
}