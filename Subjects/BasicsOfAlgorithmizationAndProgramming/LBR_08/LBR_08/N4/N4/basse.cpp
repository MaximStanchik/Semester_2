#include <iostream>
#include "queue.h"
#include <cctype>
int main() {
    setlocale(LC_ALL, "Russian");
    int size;
    std::cout << "Ведите максимальное количество элементов  в очереди: ";
    std::cin >> size;
    Queue<char> upperQueue(size);
    Queue<char> lowerQueue(size);
    Queue<char> otherQueue(size);
    int choice;
    int choiceofdelete;
    char item;
            do {
                std::cout << "\n1. Добавить элемент";
                std::cout << "\n2. Удалить элемент";
                std::cout << "\n3. Показать элемент(ы)";
                std::cout << "\n4. Выход";
                std::cout << "\nСделайте выбор: ";
                std::cin >> choice;
                if (choice >= 1 && choice <= 4) {
                    std::cout << "Вы ввели цифру " << choice << std::endl;

                    switch (choice) {
                    case 1:
                        std::cout << "Введите элемент: ";
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
                        std::cout << "Сколько первых элементов Вы хотите удалить из каждой очереди?" << std::endl;
                        std::cin >> choiceofdelete;
                        for (int i=1; i <= choiceofdelete; i++) {
                            deleteElement(upperQueue);
                            deleteElement(lowerQueue);
                            deleteElement(otherQueue);
                        }
                        break;
                    case 3:
                        std::cout << "Очередь прописных букв: ";
                        displayQueue(upperQueue);
                        std::cout << "Очередь строчных букв: ";
                        displayQueue(lowerQueue);
                        std::cout << "Очередь других символов: ";
                        displayQueue(otherQueue);
                        break;
                    case 4:
                        std::cout << "Выход из программы.";
                        break;
                    default:
                        std::cout << "Некорректный ввод.";
                    }
                }
                else {
                    std::cout << "Ошибка! Введите цифру от 1 до 4." << std::endl;
                    return 1; // закрываем программу с ошибкой
                }
            } while (choice != 4);
    return 0;
}