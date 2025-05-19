#include<iostream>


typedef unsigned char day;     //  день
typedef unsigned char month;   //  мес€ц
typedef unsigned short year;   //  год
struct Date   //дата
{
	day dd;
	month mm;
	year yyyy;
};

bool opreator >
bool opreator <
bool opreator == (Date a, Date b) {
	return a.dd == b.dd && a.mm && a.yyyy == b.yyyy;
}



int main()
{
	setlocale(LC_ALL, "Russian");
	Date date1 = {7,1,1980};
	Date date2 = {7,2,1993};
	Date date3 = {7,1,1980};

	if (date1 < date2) std::cout << "истина" << std::endl;
	else std::cout << "Ћожь" << std::endl;

	if (date1 > date2) std::cout << "истина" << std::endl;
	else std::cout << "Ћожь" << std::endl;

	if (date1 == date2) std::cout << "истина" << std::endl;
	else std::cout << "Ћожь" << std::endl;

	if (date1 == date3) std::cout << "истина" << std::endl;
	else std::cout << "Ћожь" << std::endl;



} 