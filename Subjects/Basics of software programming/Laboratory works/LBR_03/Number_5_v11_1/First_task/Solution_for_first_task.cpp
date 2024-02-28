//��� ������ ��������� ���������� �������������� ������� ��������� ���� FILE1 �� ���������� ����� � �������� � ���� ������.

//�������:����������� �� ����� FILE1 � ���� FILE2 ��� ������, ������� �������� ������ ���� �����. ����� ����� �������� ����� �  ����� FILE2.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// ������� ����������� ����� � ����� ������ �� ����� inFile � outFile
void copyLinesWithOneWord(ifstream& inFile, ofstream& outFile) {
    string line;
    while (getline(inFile, line)) {
        bool oneWord = true;
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ' ') {
                oneWord = false;
                break;
            }
        }
        if (oneWord) {
            outFile << line << endl;
        }
    }
}

// ������� ������ ������ ��������� ����� � �����
string findShortestWord(ifstream& inFile) {
    string shortestWord = "";
    string word;
    while (inFile >> word) {
        if (shortestWord == "" || word.length() < shortestWord.length()) {
            shortestWord = word;
        }
    }
    return shortestWord;
}

int main() {
    ifstream inFile("FILE1.txt");
    ofstream outFile("FILE2.txt");

    if (inFile.is_open() && outFile.is_open()) {
        copyLinesWithOneWord(inFile, outFile);
        inFile.close();
        outFile.close();

        ifstream inFile2("FILE2.txt");
        if (inFile2.is_open()) {
            string shortestWord = findShortestWord(inFile2);
            cout << "Shortest word in FILE2: " << shortestWord << endl;
            inFile2.close();
        }
        else {
            cout << "Unable to open FILE2";
        }
    }
    else {
        cout << "Unable to open files";
    }

    return 0;
}