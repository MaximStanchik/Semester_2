//Во второй программе ввод информации с клавиатуры и вывод в консольное окно должно осуществляться в главной функции, а запись в файл и чтение из файла--в функциях пользователя.Встроенные функции для работы со строками не использовать.

//Условие: Ввести с клавиатуры две строки символов, состоящих из слов, разделенных пробелами, и записать их в файл.Прочитать из файла данные.Найти самое короткое слово в первой строке и самое длинное во второй строке.Посчитать количество гласных букв в этих словах.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Функция записи двух строк в файл
void writeToFile() {
    ofstream outFile("FILE.txt");
    if (outFile.is_open()) {
        string firstLine, secondLine;
        cout << "Enter the first line: ";
        getline(cin, firstLine);
        cout << "Enter the second line: ";
        getline(cin, secondLine);
        outFile << firstLine << endl;
        outFile << secondLine << endl;
        outFile.close();
    }
    else {
        cout << "Unable to open file";
    }
}

// Функция поиска самого короткого слова в первой строке
string findShortestWord() {
    ifstream inFile("FILE.txt");
    string shortestWord = "";
    if (inFile.is_open()) {
        string line;
        getline(inFile, line);
        int start = 0;
        for (int i = 0; i <= line.length(); i++) {
            if (line[i] == ' ' || i == line.length()) {
                string word = line.substr(start, i - start);
                if (shortestWord == "" || word.length() < shortestWord.length()) {
                    shortestWord = word;
                }
                start = i + 1;
            }
        }
        inFile.close();
    }
    else {
        cout << "Unable to open file";
    }
    return shortestWord;
}

// Функция поиска самого длинного слова во второй строке
string findLongestWord() {
    ifstream inFile("FILE.txt");
    string longestWord = "";
    if (inFile.is_open()) {
        string line;
        getline(inFile, line);
        getline(inFile, line);
        int start = 0;
        for (int i = 0; i <= line.length(); i++) {
            if (line[i] == ' ' || i == line.length()) {
                string word = line.substr(start, i - start);
                if (longestWord == "" || word.length() > longestWord.length()) {
                    longestWord = word;
                }
                start = i + 1;
            }
        }
        inFile.close();
    }
    else {
        cout << "Unable to open file";
    }
    return longestWord;
}

// Функция подсчета количества гласных букв в слове
int countVowels(string word) {
    int count = 0;
    for (int i = 0; i < word.length(); i++) {
        char c = tolower(word[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}

int main() {
    writeToFile();

    string shortestWord = findShortestWord();
    cout << "Shortest word in the first line: " << shortestWord << endl;
    cout << "Number of vowels in the shortest word: " << countVowels(shortestWord) << endl;

    string longestWord = findLongestWord();
    cout << "Longest word in the second line: " << longestWord << endl;
    cout << "Number of vowels in the longest word: " << countVowels(longestWord) << endl;

    return 0;
}