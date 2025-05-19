#include <iostream>
#include "queue.h"
#include <cctype>
int main() {
    setlocale(LC_ALL, "Russian");
    int size;
    std::cout << "������ ������������ ���������� ���������  � �������: ";
    std::cin >> size;
    Queue<char> upperQueue(size);
    Queue<char> lowerQueue(size);
    Queue<char> otherQueue(size);
    int choice;
    int choiceofdelete;
    char item;
            do {
                std::cout << "\n1. �������� �������";
                std::cout << "\n2. ������� �������";
                std::cout << "\n3. �������� �������(�)";
                std::cout << "\n4. �����";
                std::cout << "\n�������� �����: ";
                std::cin >> choice;
                if (choice >= 1 && choice <= 4) {
                    std::cout << "�� ����� ����� " << choice << std::endl;

                    switch (choice) {
                    case 1:
                        std::cout << "������� �������: ";
                        std::cin >> (item);
                        if (std::isupper(item)) {
                            item = std::tolower(item);
                            insertElement(upperQueue, item);
                        }
                        else if (std::islower(item)) {
                            item = std::toupper(item);
                            insertElement(lowerQueue, item);
                        }
                        else {
                            insertElement(otherQueue, item);
                        }
                        break;
                    case 2:
                        std::cout << "������� ������ ��������� �� ������ ������� �� ������ �������?" << std::endl;
                        std::cin >> choiceofdelete;
                        for (int i=1; i <= choiceofdelete; i++) {
                            deleteElement(upperQueue);
                            deleteElement(lowerQueue);
                            deleteElement(otherQueue);
                        }
                        break;
                    case 3:
                        std::cout << "������� ��������� ����: ";
                        displayQueue(upperQueue);
                        std::cout << "������� �������� ����: ";
                        displayQueue(lowerQueue);
                        std::cout << "������� ������ ��������: ";
                        displayQueue(otherQueue);
                        break;
                    case 4:
                        std::cout << "����� �� ���������.";
                        break;
                    default:
                        std::cout << "������������ ����.";
                    }
                }
                else {
                    std::cout << "������! ������� ����� �� 1 �� 4." << std::endl;
                    return 1; // ��������� ��������� � �������
                }
            } while (choice != 4);
    return 0;
}