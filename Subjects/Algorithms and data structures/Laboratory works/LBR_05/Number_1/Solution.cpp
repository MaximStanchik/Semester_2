#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;





bool is_valid(string str) {
    stack<char> s; // создаем пустой стек для хранения открывающих скобок
    unordered_map<char, char> mapping = { {')', '('}, {']', '['}, {'}', '{'} }; // создаем словарь, который будет хранить соответствие между открывающими и закрывающими скобками
    for (char c : str) {// проходим по каждому символу в строке
        if (c == '(' || c == '[' || c == '{') { // если символ является открывающей скобкой, то помещаем его в стек
            s.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (s.empty()) { // если стек пуст, то скобки расставлены неверно
                return false;
            }
            else if (s.top() != mapping[c]) {
                return false;   // если верхний элемент стека не соответствует открывающей скобке, соответствующей закрывающей скобке, то скобки расставлены неверно
            }
            else {
                s.pop(); // иначе извлекаем верхний элемент стека
            }
        }
    }
    return s.empty(); // если после проверки стек пуст, то скобки расставлены верно
}

int main() {
    setlocale(LC_CTYPE, "ru");
    string str;
    cout << "Введите строку: ";
    getline(cin, str);
    if (is_valid(str)) {
        cout << "Скобки расставлены верно" << endl;
    }
    else {
        cout << "Скобки расставлены неверно" << endl;
    }
    return 0;
}