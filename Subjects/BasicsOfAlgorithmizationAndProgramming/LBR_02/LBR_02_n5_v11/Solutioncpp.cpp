
//fstream--������������� �����, ������� ������ ��� ��� ifstream � ofstream
//ifstream--input file stream--������ ������ �� �����
//ofstream--output file stream--����������� ���������� ������ � ����


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums; // ������ ��� �������� ����� �� �����
    int num;
    ifstream fileA("fileA.txt"); // �������� ����� ��� ������
    if (!fileA.is_open()) // �������� �� �������� �������� �����
    {
        cout << "������ �������� �����!" << endl;
        return 1; //���������� ���������� ������� � ���������� ������� ���������� � ���������� �������
    }
    while (fileA >> num) // ������ ����� �� �����, ���� ����� ������
    {
        nums.push_back(num); // ���������� ����� � ������
    }
    fileA.close(); // �������� �����
    ofstream fileB("fileB.txt"); // �������� ����� ��� ������
    if (!fileB.is_open()) // �������� �� �������� �������� �����
    {
        cout << "������ �������� �����!" << endl;
        return 1; //���������� ���������� ������� � ���������� ������� ���������� � ���������� �������
    }
    for (int i = 0; i < nums.size(); i++) // ������� ���� ����� �� �������
    {
        int count = 0; // ������� ���������� ����� � �������
        for (int j = 0; j < nums.size(); j++) // ������� ���� ����� �� �������
        {
            if (nums[i] == nums[j]) // ���� ����� ���������
            {
                count++; // ����������� �������
            }
        }
        if (count == 2) // ���� ����� ����������� ����� 2 ����
        {
            fileB << nums[i] << " "; // ���������� ����� � ����
        }
    }
    fileB.close(); // �������� �����
    return 0;
}


