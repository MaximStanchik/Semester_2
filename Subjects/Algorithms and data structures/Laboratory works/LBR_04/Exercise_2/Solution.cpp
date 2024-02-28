//Условие: В сети магазинов "ФИТ-Аудио" проводится рекламная акция. Каждый второй товар – бесплатно. Естественно, кассирам дано указание пробивать товары в таком порядке, чтобы магазин потерял как можно меньше денег.

//Что надо сделать: по списку товаров определите максимальную сумму в чеке


//Вход: натуральное число товаров(N < 10000) и далее N натуральных чисел – цены товаров.Цену товара сгенерировать(Например, от 1 до 100).
//Выход : Порядок пробивания на кассе и число – максимальная сумма чека.








#include<iostream>
#include <algorithm>
#include <cstdlib> // для функции rand()
#include <ctime> // для функции time()

void sortEverySecond(int arr[], int n);
void toSum(int arr[], int n);
void toGenerateNumbers(int arr[], int n);


int main() {
    setlocale(LC_ALL, "Russian");
    int k=0;
    int n;
    int first=0;
    int sum = 0;
    int ubyt = 0;
    std::cout << "Введите натуральное число товаров(N < 10000)" << std::endl;
    std::cin >> n;
    int* arr = new int[n];
    
    

    if (n >= 10000) {
        std::cout << "Вы ввели неправильное кол-во товаров (у Вас N больше или равно 10000)" << std::endl;
        std::cout << "Программа закончит свое выполнение" << std::endl;
    }
    else if (n < 0) {
        std::cout << "Вы ввели неправильное кол-во товаров (у Вас N меньше 0)" << std::endl;
        std::cout << "Программа закончит свое выполнение" << std::endl;
    }
    else if (n < 10000 && n>0) {
        std::cout << "1--ввести цены на товары самостоятельно" << std::endl;
        std::cout << "2--сгенерировать случайные цены на товары" << std::endl;
        std::cout << "любая другая клавиша--выход из программы" << std::endl;
    }
    std::cin >> k;
        switch (k) {
        case 1:
            
            for (int i = 0; i < n; i++) {		//рандомные цены товаров
                arr[i] = rand() % 100 + 1;
                std::cout << arr[i] << " ";
                sum += arr[i];
            }
            std::cout << std::endl << std::endl;
            std::cout << "Сумма товаров: " << sum << std::endl << std::endl;

            for (int i = 0; i < n; i++) {		//сортировка массива
                for (int j = 0; j < n - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        int b = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = b;

                    }
                }
            }

            std::cout << "Последовательность пробития кассиром: " << std::endl;
            int i = 0;
            int j = n - 1;
            while (j > i) {
                std::cout << arr[j] << " ";
                std::cout << arr[i] << " ";
                ubyt += arr[i];
                i++; j--;
            }
            if (n % 2 != 0) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl << std::endl << "Убыток магазина составляет: " << ubyt << std::endl;
        



            break;
        case 2:
            
           
            for (int i = 0; i < n; i++) {		//рандомные цены товаров
                arr[i] = rand() % 100 + 1;
                std::cout << arr[i] << " ";
                sum += arr[i];
            }
            std::cout << std::endl << std::endl;
            std::cout << "Сумма товаров: " << sum << std::endl << std::endl;

            for (int i = 0; i < n; i++) {		//сортировка массива
                for (int j = 0; j < n - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        int b = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = b;

                    }
                }
            }

            std::cout << "Последовательность пробития кассиром: " << std::endl;
            int i = 0;
            int j = n - 1;
            while (j > i) {
                std::cout << arr[j] << " ";
                std::cout << arr[i] << " ";
                ubyt += arr[i];
                i++; j--;
            }
            if (n % 2 != 0) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl << std::endl << "Убыток магазина составляет: " << ubyt << std::endl;
}

            break;
        }

        std::cout << "Программа закончила свое выполнение" << std::endl;
        return 0;
    }
    
//
//void sortEverySecond(int arr[], int n) {
//    // Сортируем весь массив по возрастанию
//    std::sort(arr, arr + n);
//
//    // Меняем местами каждую пару чисел, начиная со второго
//    for (int i = 1; i < n - 1; i += 2) {
//        std::swap(arr[i], arr[i + 1]);
//    }
//}
//
//
//
//void toGenerateNumbers(int arr[], int n) {
//    for (int i = 0; i < n; ++i)
//        std::cout << arr[i] << " ";
//    std::cout << std::endl;
//}