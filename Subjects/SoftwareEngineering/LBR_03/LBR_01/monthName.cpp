#include "stdafx.h"
using namespace std;
void monthName(int month) {
	setlocale(LC_CTYPE, "");
	string names[12] = { "€нвар€", "феврал€", "марта", "апрел€", "ма€", "июн€", "июл€", "августа", "сент€бр€", "окт€бр€", "но€бр€", "декабр€" };
	cout << names[month - 1] << endl << endl;

}