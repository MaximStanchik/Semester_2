
#include"SE_Lab06L.h"
using namespace std;

namespace dictionary
{
	Instance Create(const char* name, int size)
	{
		if (strlen(name) > DICTNAMEMAXSIZE) //strlen--размер слова
			throw (char*)THROW01;
		if (size > DICTMAXSIZE) //size--кол-во слов в словаре
			throw (char*)THROW02;
		Instance newDict;
		strcpy_s(newDict.name, name);
		newDict.maxsize = size;
		newDict.size = 0;
		return newDict;
	};

	void AddEntry(Instance& inst, Entry ed)
	{
		if (inst.size == inst.maxsize)
			throw (char*)THROW03;
		for (int i = 0; i < inst.size; i++)
			if (ed.id == inst.dictionary[i]->id)
				throw (char*)THROW04;

		inst.dictionary[inst.size] = new Entry();
		inst.dictionary[inst.size]->id = ed.id;
		strcpy_s(inst.dictionary[inst.size]->name, ed.name);
		inst.size++;
	};

	void DelEntry(Instance& inst, int id)
	{
		int k = inst.size;
		if (id > k)
			throw (char*)THROW06;
		for (int i = 0; i < inst.size; i++) {
			if (inst.dictionary[i]->id == id) {
				delete inst.dictionary[i];
				if (i == inst.size - 1) inst.dictionary[i] = NULL;
				else {
					for (int j = i; j < inst.size - 1; j++) {
						inst.dictionary[j] = inst.dictionary[j + 1];
					}
					inst.dictionary[inst.size - 1] = NULL;
				}
				inst.size--;
				break;
			}
		}
	};
	void UpdEntry(Instance& inst, int id, Entry new_ed) //Назначение: Изменить элемент словаря.
	{
		int k = inst.size; //k--размер словаря объекта inst
		for (int i = 0; i < inst.size; i++) { //тут мы проходимся по всем элементам словаря
			if (inst.dictionary[i]->id == id) {
				if (inst.dictionary[i]->id == new_ed.id) throw (char*)THROW08; //UpdEntry: Дублированеие идентификатора
				inst.dictionary[i]->id = new_ed.id;
				strcpy_s(inst.dictionary[i]->name, new_ed.name);
			}
			else
				throw (char*)THROW07; //UpdEntry: Элемент не найден
		}
	};
	Entry GetEntry(Instance inst, int id)
	{
		Entry getElement;
		int k = inst.size;
		if (id > k) {
			throw (char*)THROW06;
		}
		for (int i = 0; i < inst.size; i++) {
			if (id == inst.dictionary[i]->id) {
				getElement.id = inst.dictionary[i]->id;
				for (int j = 0; j < strlen(inst.dictionary[i]->name); j++)
					getElement.name[j] = inst.dictionary[i]->name[j];
				return getElement;
			}
		}
	};
	void Print(Instance d)
	{
		std::cout << "-------" << d.name << "-------" << std::endl;
		for (int i = 0; i < d.size; i++) {
			std::cout << d.dictionary[i]->id << " " << d.dictionary[i]->name << std::endl;
		}

	};
	void Delete(Instance& d)
	{
		for (int i = 0; i < d.size; i++) {
			delete d.dictionary[i];
		}
		d.maxsize = NULL;
		d.size = NULL;
		*d.name = NULL;
	};
};