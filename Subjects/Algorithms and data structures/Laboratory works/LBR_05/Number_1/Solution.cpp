#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;





bool is_valid(string str) {
    stack<char> s; // ������� ������ ���� ��� �������� ����������� ������
    unordered_map<char, char> mapping = { {')', '('}, {']', '['}, {'}', '{'} }; // ������� �������, ������� ����� ������� ������������ ����� ������������ � ������������ ��������
    for (char c : str) {// �������� �� ������� ������� � ������
        if (c == '(' || c == '[' || c == '{') { // ���� ������ �������� ����������� �������, �� �������� ��� � ����
            s.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (s.empty()) { // ���� ���� ����, �� ������ ����������� �������
                return false;
            }
            else if (s.top() != mapping[c]) {
                return false;   // ���� ������� ������� ����� �� ������������� ����������� ������, ��������������� ����������� ������, �� ������ ����������� �������
            }
            else {
                s.pop(); // ����� ��������� ������� ������� �����
            }
        }
    }
    return s.empty(); // ���� ����� �������� ���� ����, �� ������ ����������� �����
}

int main() {
    setlocale(LC_CTYPE, "ru");
    string str;
    cout << "������� ������: ";
    getline(cin, str);
    if (is_valid(str)) {
        cout << "������ ����������� �����" << endl;
    }
    else {
        cout << "������ ����������� �������" << endl;
    }
    return 0;
}