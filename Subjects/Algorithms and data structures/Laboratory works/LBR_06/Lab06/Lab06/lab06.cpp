#include "Hash_Twin_Chain.h"
#include <iostream>
#include <windows.h>
#include <tchar.h> //���������� ������� ��� ������ � ��������� Unicode � ASCII � ����������� �� �������� �����������. 
#include <time.h> //��������� ���������� ��� ������ �� �������� � ������.
#include <algorithm> //�������� ������� ��� ������ � ������������, ����� ��� ����������, ����� � �.�.
#include <vector> //���������� ����� ���������� vector, ������� ������������ ����� ������������ ������ ���������.

using namespace std;

struct AAA //���������� ��� ���������, ������� ����� ��������� � �������.
{
	int key; //������������� ��������
	const char* mas; //���� ��������--��������� �� ����������� ������
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

int hf(void* d) //���������e ���-�������� �����                                                                       
{
	AAA* f = (AAA*)d;
	return f->key;
}

void AAA_print(listx::Element* e) //����� �������� �� ����� 
{
	std::cout << ((AAA*)e->data)->key << '-' << ((AAA*)e->data)->mas;
}

int _tmain(int argc, _TCHAR* argv[])
{                                                         
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int current_size{};
	cout << "������� ������ ���-�������: ";                            
	cin >> current_size;
	hashTC::Object H = hashTC::create(current_size, hf); //�������� ���-������� � �������� �������� � ���-�������� hf
	vector<int> keys;
	clock_t start, end;
	double searching_time;
	int choice;
	int k;
	for (;;)																	
	{
		cout << "\n1 - ������� ���-������� � �������" << endl;
		cout << "2 - �������� ����� �������" << endl;
		cout << "3 - ������� �������" << endl;
		cout << "4 - ����� �������" << endl;
		cout << "0 - �����" << endl;
		cout << "������� ����� ����� ��������� ��������:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 2: {	  AAA* a = new AAA; //�������� ����� ������ ������ AAA � ���������� ������ ��� ����.            
			char* str = new char[100];
			bool is_correct = false;
			do {
				cout << "������� ����� ��������: ";
				cin >> k; //������ ����
				k = k;
				a->key = k;
				if (std::count(keys.begin(), keys.end(), k) == 0 and k > -1) {
					keys.push_back(k);
					is_correct = true;
				}
				else cout << "�������� ����" << endl;
			} while (!is_correct);
			cout << "������� ���: ";
			cin.ignore(); //������� ������ �����
			cin.getline(str, 100);
			a->mas = str;
			H.insert(a);
		}
			  break;
		case 1: H.Scan();
			break;
		case 3: {	  AAA* b = new AAA;
			cout << "������� ����� ��������, ����� ������� ������: ";
			cin >> k;
			b->key = k;
			keys.erase(std::find(keys.begin(), keys.end(), k));
			H.deleteByData(b);
		}
			  break;
		case 4: {AAA* c = new AAA;
			cout << "������� ����� ��������, ����� ����� ������: ";
			cin >> k;
			c->key = k;
			start = clock();
			if (H.search(c) == NULL)
				cout << "������� �� ������" << endl;
			else
			{
				cout << "������� � ������ ���������� �������: ";
				AAA_print(H.search(c));
				cout << endl;
			}
			end = clock();
			searching_time = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "����� ������: " << searching_time << endl;
		}
			  break;
		}
	}
	return 0;
}