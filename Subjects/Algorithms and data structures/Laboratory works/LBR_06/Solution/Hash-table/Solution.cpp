#include <iostream>
#include <string>
#include <vector>
#include <chrono> // для измерения времени

using namespace std;
using namespace std::chrono; // для измерения времени

const int MAX_NUM = 32767;

struct Record {
    int phone;
    string name;
};

class HashTable {
private:
    vector<vector<Record>> table;
    int size;

public:
    HashTable(int size) {
        this->size = size;
        table.resize(size);
    }

    int hash(int key) {
        return key % size;
    }

    void insert(int phone, string name) {
        int index = hash(phone);
        Record r = { phone, name };
        table[index].push_back(r);
    }

    bool remove(int phone) {
        int index = hash(phone);
        for (int i = 0; i < table[index].size(); i++) {
            if (table[index][i].phone == phone) {
                table[index].erase(table[index].begin() + i);
                return true;
            }
        }
        return false;
    }

    Record* find(int phone) {
        int index = hash(phone);
        for (int i = 0; i < table[index].size(); i++) {
            if (table[index][i].phone == phone) {
                return &table[index][i];
            }
        }
        return nullptr;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << ": ";
            for (int j = 0; j < table[i].size(); j++) {
                cout << table[i][j].phone << " " << table[i][j].name << ", ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht16(16);
    ht16.insert(1234567, "John Smith");
    ht16.insert(7654321, "Jane Doe");
    ht16.insert(5551212, "Bob Johnson");

    HashTable ht32(32);
    ht32.insert(1234567, "John Smith");
    ht32.insert(7654321, "Jane Doe");
    ht32.insert(5551212, "Bob Johnson");

    HashTable ht64(64);
    ht64.insert(1234567, "John Smith");
    ht64.insert(7654321, "Jane Doe");
    ht64.insert(5551212, "Bob Johnson");

    // Измерение времени поиска
    auto start = high_resolution_clock::now();
    Record* r = ht16.find(1234567);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    if (r != nullptr) {
        cout << "Found in ht16: " << r->name << endl;
        cout << "Time taken: " << duration.count() << " microseconds" << endl;
    }
    else {
        cout << "Not found in ht16" << endl;
    }

    start = high_resolution_clock::now();
    r = ht32.find(1234567);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    if (r != nullptr) {
        cout << "Found in ht32: " << r->name << endl;
        cout << "Time taken: " << duration.count() << " microseconds" << endl;
    }
    else {
        cout << "Not found in ht32" << endl;
    }

    start = high_resolution_clock::now();
    r = ht64.find(1234567);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    if (r != nullptr) {
        cout << "Found in ht64: " << r->name << endl;
        cout << "Time taken: " << duration.count() << " microseconds" << endl;
    }
    else {
        cout << "Not found in ht64" << endl;
    }

    return 0;
}