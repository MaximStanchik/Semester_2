//fstream--������������� �����, ������� ������ ��� ��� ifstream � ofstream
//ifstream--input file stream--������ ������ �� �����
//ofstream--output file stream--����������� ���������� ������ � ����
// 
// 
// 
//������� ��������� ���� F1 �� �����, ��� �� 6 �����, � �������� � ���� ����������.����������� � ���� F2 ������ �� ������ �� F1, ������� ������������� �������� ��.

//��������� �� ���������� �
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    // ��������� ���� ��� ������
    ifstream fin("F1.txt");
    // ��������� ���� ��� ������
    ofstream fout("F2.txt");
    // ���������� ��� �������� ������� ������
    string line;
    // ��������� ������ �� ����� F1
    while (getline(fin, line)) {
        // ���� ������ ������������� �������� 'a', �� ���������� �� � ���� F2
        if (line.back() == 'a') {
            fout << line << endl;
        }
    }
    // ��������� �����
    fin.close();
    fout.close();
    return 0;
}
