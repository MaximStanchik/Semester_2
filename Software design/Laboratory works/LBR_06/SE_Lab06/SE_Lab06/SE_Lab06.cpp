#pragma comment (lib,"D:\\User\\Desktop\\Everythin' for BSTU\\Narkevich\\1-ый курс 2-ой семестр\\Lab's\\решения лбр\\LBR_06\\SE_Lab06\\x64\\Debug\\SE_Lab06L.lib")
#include "SE_Lab06.h"
#include "D:\User\Desktop\Everythin' for BSTU\Narkevich\1-ый курс 2-ой семестр\Lab's\решения лбр\LBR_06\SE_Lab06\SE_Lab06L\SE_Lab06L.h"
using namespace std;
using namespace dictionary;

#if defined(TEST01)+defined(TEST02)+defined(TEST03)+defined(TEST04)+defined(TEST05)+defined(TEST06)+defined(TEST07)+defined(TEST08)+defined(TEST09)>1
#error "Вызываеться слишком много проверок"
#endif

int main() {
	setlocale(LC_ALL, "ru");
	try { //try--для обработки исключений
#ifdef TEST01 //длина названия
		Instance test = Create((char*)"HHHHHHHHHHHHHHHEEEEEEEEEEEEEEEEEEEELLLLLLLLLLLLLLLLLLLLLLLLLLOOOOOOOOOOOOOOOOOOOOOOOO", 5);
#endif // TEST01

#ifdef TEST02 //проверка кол-ва слов в словаре
		Instance test = Create((char*)"TEST", 5000000);
#endif // TEST02

#ifdef TEST03 //переволнение словаря
		Instance test = Create((char*)"TEST", 0);
		Entry test_e = { 1,"aaaaa" };
		AddEntry(test, test_e);
#endif // TEST03

#ifdef TEST04 //дублирование словаря
		Instance test = Create((char*)"TEST", 5);
		Entry test_e = { 1,"aaaaa" };
		AddEntry(test, test_e);
		AddEntry(test, test_e);
#endif // TEST04

#ifdef TEST05 //поиск элемента
		Instance test = Create((char*)"TEST", 5);
		Entry test_e = { 1,"aaaaaaaaa" };
		AddEntry(test, test_e);
		GetEntry(test, 2);
#endif // TEST05

#ifdef TEST06 //поиск элемента
		Instance test = Create((char*)"TEST", 5);
		Entry test_e = { 1,"aaaaaaaaaa" };
		AddEntry(test, test_e);
		DelEntry(test, 2);
#endif // TEST06

#ifdef TEST07
		Instance test7 = Create((char*)"TEST", 5);
		Entry test_e7 = { 1,"aaaaaaaaaa" }, test_upd_e7 = { 2,"zzzzzzzz" };
		AddEntry(test7, test_e7);
		UpdEntry(test7, 3, test_upd_e7);
#endif // TEST07

#ifdef TEST08 //дублирование интерфейса
		Instance test = Create((char*)"TEST", 5);
		Entry test_e = { 1,"aaaaaaaaa" }, test_upd_e = { 1,"zzzzzzzz" };
		AddEntry(test, test_e);
		UpdEntry(test, 1, test_upd_e);
#endif // TEST08

#ifdef TEST09 //ввод нормальных данных в словарь и показ данных словаря
		Instance d1 = Create((char*)"Lecturers", 5);
		Entry	e1 = { 1,"One" }, e2 = { 2,"Two" }, e3 = { 3,"Three" }, e4 = { 4, "Fore" }, e5 = { 5, "Five" };
		AddEntry(d1, e1);
		AddEntry(d1, e2);
		AddEntry(d1, e3);
		AddEntry(d1, e4);
		Entry getE = GetEntry(d1, 4);
		DelEntry(d1, 2);
		Entry newentry1 = { 6, "Hello" };
		UpdEntry(d1, 3, newentry1);
		Print(d1);
		Instance d2 = Create((char*)"Students", 5);
		Entry s1 = { 1,"First" }, s2 = { 2,"Second" }, s3 = { 4,"Thred" };
		AddEntry(d2, s1);
		AddEntry(d2, s2);
		AddEntry(d2, s3);
		Entry newentry3 = { 3, "Good-by" };
		UpdEntry(d2, 4, newentry3);
		Print(d2);
		Delete(d1);
		Delete(d2);
#endif // TEST09
	}
	catch (char* e) {
		cout << e << endl;
	}
	return 0;
}