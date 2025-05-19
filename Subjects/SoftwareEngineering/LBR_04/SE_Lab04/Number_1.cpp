#include <iostream>

using namespace std;

typedef unsigned char day;
typedef unsigned char mounth;
typedef unsigned short year;

struct Date {
	day dd;
	mounth mm;
	year yyyy;
};


bool operator < (Date a, Date b) {
	if (a.yyyy < b.yyyy) {
		return true;
	}
	else if (a.yyyy > b.yyyy) {
		return false;
	}
	else if (b.yyyy == a.yyyy){
		if (a.mm < b.mm) {
			return true;
		}
		else if (a.mm > b.mm) {
			return false;
		}
		else if (a.mm == b.mm) {
				
			if (a.dd < b.dd) {
				return true;
			}
			else if (a.dd >= b.dd){
			    return false;	
			}
		}
	}
}


bool operator > (Date a, Date b) {
	return operator < (b, a);
}
	

bool operator ==(Date a, Date b) {
	return a.dd == b.dd && a.mm == b.mm && a.yyyy == b.yyyy;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Date date1 = { 7,1,1980 };
	Date date2 = { 7,2,1993 };
	Date date3 = { 7,1,1980 };

	if (date1 < date2)
		cout << "Èñòèíà" << endl;
	else
		cout << "Ëîæü"<<endl;

	if (date1 > date2)
		cout << "Èñòèíà"<<endl;
	else
		cout << "Ëîæü" << endl;

	if (date1 == date2)
		cout << "Èñòèíà" << endl;
	else
		cout << "Ëîæü" << endl;

	if (date1 == date3)
		cout << "Èñòèíà" << endl;
	else
		cout << "Ëîæü" << endl;
}