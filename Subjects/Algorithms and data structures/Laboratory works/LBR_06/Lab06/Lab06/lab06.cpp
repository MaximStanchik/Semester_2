#include "Hash_Twin_Chain.h"
#include <iostream>
#include <windows.h>
#include <tchar.h> //определяет макросы для работы с символами Unicode и ASCII в зависимости от настроек компилятора. 
#include <time.h> //одключает библиотеку для работы со временем и датами.
#include <algorithm> //содержит функции для работы с контейнерами, такие как сортировка, поиск и т.д.
#include <vector> //определяет класс контейнера vector, который представляет собой динамический массив элементов.

using namespace std;

struct AAA //определяем тип элементов, которые будут храниться в таблице.
{
	int key; //целочисленное значение
	const char* mas; //само значение--указатель на константную строку
	AAA(int k, const char* z)
	{
		key = k;
		mas = z;
	}
	AAA()
	{
		key = 0;
		mas = NULL;
	}
};

int hf(void* d) //вычислениe хэш-значения ключа                                                                       
{
	AAA* f = (AAA*)d;
	return f->key;
}

void AAA_print(listx::Element* e) //вывод элемента на экран 
{
	std::cout << ((AAA*)e->data)->key << '-' << ((AAA*)e->data)->mas;
}

int _tmain(int argc, _TCHAR* argv[])
{                                                         
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int current_size{};
	cout << "Введите размер хэш-таблицы: ";                            
	cin >> current_size;
	hashTC::Object H = hashTC::create(current_size, hf); //создание хэш-таблицы с заданным размером и хэш-функцией hf
	vector<int> keys;
	clock_t start, end;
	double searching_time;
	int choice;
	int k;
	for (;;)																	
	{
		cout << "\n1 - Вывести хэш-таблицу в консоль" << endl;
		cout << "2 - Добавить новый элемент" << endl;
		cout << "3 - Удалить элемент" << endl;
		cout << "4 - Найти элемент" << endl;
		cout << "0 - Выход" << endl;
		cout << "Введите цифру чтобы выполнить действие:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 2: {	  AAA* a = new AAA; //оздается новый объект класса AAA и выделяется память под него.            
			char* str = new char[100];
			bool is_correct = false;
			do {
				cout << "Введите номер телефона: ";
				cin >> k; //вводим ключ
				k = k;
				a->key = k;
				if (std::count(keys.begin(), keys.end(), k) == 0 and k > -1) {
					keys.push_back(k);
					is_correct = true;
				}
				else cout << "Неверный ввод" << endl;
			} while (!is_correct);
			cout << "Введите ФИО: ";
			cin.ignore(); //очистка буфера ввода
			cin.getline(str, 100);
			a->mas = str;
			H.insert(a);
		}
			  break;
		case 1: H.Scan();
			break;
		case 3: {	  AAA* b = new AAA;
			cout << "Введите номер телефона, чтобы удалить запись: ";
			cin >> k;
			b->key = k;
			keys.erase(std::find(keys.begin(), keys.end(), k));
			H.deleteByData(b);
		}
			  break;
		case 4: {AAA* c = new AAA;
			cout << "Введите номер телефона, чтобы найти запись: ";
			cin >> k;
			c->key = k;
			start = clock();
			if (H.search(c) == NULL)
				cout << "Элемент не найден" << endl;
			else
			{
				cout << "Элемент с данным телефонным номером: ";
				AAA_print(H.search(c));
				cout << endl;
			}
			end = clock();
			searching_time = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "Время поиска: " << searching_time << endl;
		}
			  break;
		}
	}
	return 0;
}