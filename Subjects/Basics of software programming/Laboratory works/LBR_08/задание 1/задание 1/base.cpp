#include <iostream>
#include "queue.h"
#include <cctype>
int main() {
    setlocale(LC_ALL, "Russian");
    int size;
    std::cout << "Ведите максимальное количество элементов  в очереди: ";
    std::cin >> size;
    Queue<char> charQueue(size);
    int choice;
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
                    insertElement(charQueue, item);
                        break;
                    case 2:
                        deleteElement(charQueue);
                        break;
                    case 3:
                        displayQueue(charQueue);
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
