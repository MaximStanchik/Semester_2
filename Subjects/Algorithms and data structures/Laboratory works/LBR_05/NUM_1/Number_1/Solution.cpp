
#include <iostream>
#include <stack>
#include <string>

using namespace std;

//тут мы создаем стек символов.
//Если после обработки всех символов стек не пустой, это означает, что в строке были непарные скобки, и функция возвращает false.
bool checkBrackets(string str) {
    stack<char> st;
    for (char c : str) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) {
                return false; 
            }
            else if ((c == ')' && st.top() == '(') ||
                (c == ']' && st.top() == '[') ||
                (c == '}' && st.top() == '{')) {
                st.pop();
            }
            else {
                return false; 
            }
        }
    }
    return st.empty();
}

int main() {
    setlocale(LC_CTYPE, "ru");
    string str;
    cout << "Введите строку: ";
    getline(cin, str);
    if (checkBrackets(str)) {
        cout << "Скобки расставлены верно" << endl;
    }
    else {
        cout << "Скобки расставлены не верно" << endl;
    }
    return 0;
}