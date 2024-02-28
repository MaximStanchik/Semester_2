
#include <iostream>
#include <stack>
#include <string>

using namespace std;

//��� �� ������� ���� ��������.
//���� ����� ��������� ���� �������� ���� �� ������, ��� ��������, ��� � ������ ���� �������� ������, � ������� ���������� false.
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
    cout << "������� ������: ";
    getline(cin, str);
    if (checkBrackets(str)) {
        cout << "������ ����������� �����" << endl;
    }
    else {
        cout << "������ ����������� �� �����" << endl;
    }
    return 0;
}