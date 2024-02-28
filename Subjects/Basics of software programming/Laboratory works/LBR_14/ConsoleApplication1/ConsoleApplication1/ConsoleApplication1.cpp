#include <iostream>
#include <unordered_map>
#include <chrono>

template<typename Func>
double measureExecutionTime(Func&& func)
{
    auto startTime = std::chrono::high_resolution_clock::now();
    func();
    auto endTime = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = endTime - startTime;
    return duration.count();
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int tableSize;
    std::cout << "Введите размер хеш-таблицы: ";
    std::cin >> tableSize;

    std::unordered_map<int, int> hashTable;
    const int numElements = 10000;

    for (int i = 0; i < numElements; ++i)
    {
        int key = i % tableSize; 
        hashTable[key] = i;
    }

    auto accessElements = [tableSize, &hashTable, numElements]() {
        for (int i = 0; i < numElements; ++i)
        {
            int key = i % tableSize;
            int value = hashTable[key];
        }
    };

    double executionTime = measureExecutionTime(accessElements);
    std::cout << "Затраченное время: " << executionTime << " секунд" << std::endl;

    return 0;
}
