#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

bool isEven(int num) {
    return num % 2 == 0;
}

void shellSort(std::vector<int>& arr, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[low];
        int i = low + 1;
        int j = high;

        while (i <= j) {
            while (i <= j && arr[i] < pivot) {
                i++;
            }
            while (i <= j && arr[j] > pivot) {
                j--;
            }

            if (i <= j) {
                std::swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        std::swap(arr[low], arr[j]);

        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int sizeA, sizeB;
    std::cout << "Введите размер массива A: ";
    std::cin >> sizeA;
    std::cout << "Введите размер массива B: ";
    std::cin >> sizeB;

    std::vector<int> A(sizeA);
    std::vector<int> B(sizeB);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100); 

    std::cout << "Массив A (исходный): ";
    for (int i = 0; i < sizeA; i++) {
        int num = dist(gen);
        if (!isEven(num)) {
            A[i] = num;
            std::cout << A[i] << " ";
        }
        else {
            i--;
        }
    }
    std::cout << std::endl;

    std::cout << "Массив B (исходный): ";
    for (int i = 0; i < sizeB; i++) {
        int num = dist(gen);
        if (isEven(num)) {
            B[i] = num;
            std::cout << B[i] << " ";
        }
        else {
            i--;
        }
    }
    std::cout << std::endl;

    std::vector<int> C;

    for (int i = 0; i < sizeA; i++) {
        if (!isEven(A[i])) {
            C.push_back(A[i]);
        }
    }

    for (int i = 0; i < sizeB; i++) {
        if (isEven(B[i])) {
            C.push_back(B[i]);
        }
    }

    shellSort(C, C.size());

    std::cout << "Отсортированный массив C (сортировка Шелла): ";
    for (int i = 0; i < C.size(); i++) {
        std::cout << C[i] << " ";
    }
    std::cout << std::endl;
    
    quickSort(C, 0, C.size() - 1);

    std::cout << "Отсортированный массив C (сортировка Хоара): ";
    for (int i = 0; i < C.size(); i++) {
        std::cout << C[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
