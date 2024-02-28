#include <iostream>
#include <string>
#include <unordered_map>

struct City {
    std::string name;
    int population;

    City(const std::string& cityName, int cityPopulation)
        : name(cityName), population(cityPopulation) {}

    bool operator==(const City& other) const {
        return population == other.population;
    }
};


struct HashFunction {
    size_t operator()(const City& city) const {
        return city.population ^ (city.population >> 16);
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    std::unordered_map<City, std::string, HashFunction> cityTable;
    cityTable.reserve(10); 

    cityTable.emplace(City("Минск", 500), "Беларусь");
    cityTable.emplace(City("Токио", 1000), "Япония");
    cityTable.emplace(City("Пекин", 2000), "Китай");
    cityTable.emplace(City("Лондон", 3000), "Великобритания");
    cityTable.emplace(City("Париж", 5000), "Франция");

    int searchPopulation;
    std::cout << "Введите численность населения для поиска: ";
    std::cin >> searchPopulation;

    City searchCity("", searchPopulation);
    auto iter = cityTable.find(searchCity);

    if (iter != cityTable.end()) {
        std::cout << "Город найден: " << iter->first.name << ", Население: " << iter->first.population << ", Страна: " << iter->second << std::endl;
    }
    else {
        std::cout << "Город с заданной численностью населения не найден." << std::endl;
    }

    return 0;
}
