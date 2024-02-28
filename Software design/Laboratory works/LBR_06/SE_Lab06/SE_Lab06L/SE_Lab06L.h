#pragma once 

#include <iostream>
#include <cstring> //это библиотека 

#define DICTNAMEMAXSIZE 20 //максимальное значение символов в слове в словаре
#define DICTMAXSIZE 100 //максимальное значение кол-ва слов словар€
#define ENTRYNAMEMAXSIZE 20 //максимальное значение символов в слове в словаре 

#define THROW01 "Create: превышен размер имени словар€ "
#define THROW02 "Create: превышен размер максимальной Ємкости словар€"
#define THROW03 "AddEntry: —ловарь переполнен"
#define THROW04 "AddEntry: ƒублирование идентификатора"
#define THROW05 "GetEntry: Ёлемент не найден"
#define THROW06 "DelEntry: Ёлемент не найден"
#define THROW07 "UpdEntry: Ёлемент не найден"
#define THROW08 "UpdEntry: ƒублирование идентификатора"

namespace dictionary
{
	struct Entry //¬ход
	{
		int id; //потом используем где размер слова
		char name[ENTRYNAMEMAXSIZE]; //name--само слово []-- массив и его максимальное значение символов=ENTRYNAMEMAXSIZE=20
	};

	struct Instance //образец
	{
		char name[DICTNAMEMAXSIZE];
		int maxsize;
		int size;
		Entry* dictionary[DICTNAMEMAXSIZE];
	};

	Instance Create(const char* name, int size);
	void AddEntry(Instance& inst, Entry ed);
	void DelEntry(Instance& inst, int id);
	void UpdEntry(Instance& inst, int id, Entry new_ed);
	Entry GetEntry(Instance inst, int id);
	void Print(Instance d);
	void Delete(Instance& d);

};
