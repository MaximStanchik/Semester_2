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
        if (isFull()) {
            std::cout << "Очередь полная, невозможно добавить больше элементов\n";
            return;
        }
        m_queue.push(item);
    }
    void pop() {
        if (isEmpty()) {
            std::cout << "Очередь пуста. Невозможно удалить элементы.\n";
            return;
        }
        T item = m_queue.front();
        m_queue.pop();
        std::cout << "Элемент " << item << " удалён из очереди.\n";
    }
    void display() {
        if (isEmpty()) {
            std::cout << " Очередь пуста. .\n";
            return;
        }
        std::queue<T> temp = m_queue;
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