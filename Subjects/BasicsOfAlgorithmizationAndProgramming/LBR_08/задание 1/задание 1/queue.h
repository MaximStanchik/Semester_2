#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include <queue>
template <typename T>
class Queue {
private:
    std::queue<T> m_queue;
    int m_maxSize;
public:
    Queue(int maxSize) : m_maxSize(maxSize) {}
    bool isFull() {
        return m_queue.size() == m_maxSize;
    }
    bool isEmpty() {
        return m_queue.empty();
    }
    void push(T item) {
        setlocale(LC_ALL, "Russian");
        if (isFull()) {
            std::cout << "������� ������, ���������� �������� ������ ���������\n";
            return;
        }

        if (std::isupper(item)) {
            item = std::tolower(item);
            m_queue.push(item);
            std::cout << "������� " << item << " �������� � �������.\n";
        }
        else if (std::islower(item)) {
            item = std::toupper(item);
            m_queue.push(item);
            std::cout << "������� " << item << " �������� � �������.\n";
        }
    }
    void pop() {
        if (isEmpty()) {
            std::cout << "������� �����. ���������� ������� ��������.\n";
            return;
        }
        T item = m_queue.front();
        m_queue.pop();
        std::cout << "������� " << item << " ����� �� �������.\n";
    }
    void display() {
        if (isEmpty()) {
            std::cout << " ������� �����. .\n";
            return;
        }
        std::queue<T> temp = m_queue;
        std::cout << "�������� �������: ";
        while (!temp.empty()) {
            std::cout << temp.front() << " ";
            temp.pop();
        }
        std::cout << std::endl;
    }
};
template <typename T>
void insertElement(Queue<T>& queue, T item) {
    queue.push(item);
}
template <typename T>
void deleteElement(Queue<T>& queue) {
    queue.pop();
}
template <typename T>
void displayQueue(Queue<T>& queue) {
    queue.display();
}

#endif
