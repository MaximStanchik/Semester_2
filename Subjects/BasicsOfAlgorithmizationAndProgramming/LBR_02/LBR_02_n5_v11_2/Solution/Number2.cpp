//fstream--универсальный класс, который делает все что ifstream и ofstream
//ifstream--input file stream--чтение данных из файла
//ofstream--output file stream--возможность сохранения данных в файл
// 
// 
// 
//Создать текстовый файл F1 не менее, чем из 6 строк, и записать в него информацию.Скопировать в файл F2 только те строки из F1, которые заканчиваются символом «а».

//реагирует на английскую а
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    // открываем файл для чтения
    ifstream fin("F1.txt");
    // открываем файл для записи
    ofstream fout("F2.txt");
    // переменная для хранения текущей строки
    string line;
    // считываем строки из файла F1
    while (getline(fin, line)) {
        // если строка заканчивается символом 'a', то записываем ее в файл F2
        if (line.back() == 'a') {
            fout << line << endl;
        }
    }
    // закрываем файлы
    fin.close();
    fout.close();
    return 0;
}
