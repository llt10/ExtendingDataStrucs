#include <iostream>
#include <vector>

template <typename T>
class Queue {
private:
    T* data;
    int capacity;
    int count;
    int front;

    void grow() {
        int newCap = capacity * 2;
        T* newData = new T[newCap];
        for (int i = 0; i < count; i++) {
            newData[i] = data[(front + i) % capacity];
        }
        delete[] data;
        data = newData;
        capacity = newCap;
        front = 0;
    }

public:
    Queue() {
        capacity = 4;
        data = new T[capacity];
        count = 0;
        front = 0;
    }

    void push(const T& value) {
        if (count == capacity) {
            grow();
        }
        int index = (front + count) % capacity;
        data[index] = value;
        count++;
    }

    T pop() {
        T value = data[front];
        front = (front + 1) % capacity;
        count--;
        return value;
    }

    bool empty() const {
        return count == 0;
    }
};

template <typename T>
class Quack {
private:
    T* data;
    int capacity;
    int count;
    int front;

    void grow() {
        int newCap = capacity * 2;
        T* newData = new T[newCap];
        for (int i = 0; i < count; i++) {
            newData[i] = data[(front + i) % capacity];
        }
        delete[] data;
        data = newData;
        capacity = newCap;
        front = 0;
    }

public:
    Quack() {
        capacity = 4;
        data = new T[capacity];
        count = 0;
        front = 0;
    }

    void push_front(const T& value) {
        if (count == capacity) {
            grow();
        }
        front = (front - 1 + capacity) % capacity;
        data[front] = value;
        count++;
    }

    void push_back(const T& value) {
        if (count == capacity) {
            grow();
        }
        int index = (front + count) % capacity;
        data[index] = value;
        count++;
    }

    T pop_front() {
        T value = data[front];
        front = (front + 1) % capacity;
        count--;
        return value;
    }

    T pop_back() {
        int index = (front + count - 1) % capacity;
        T value = data[index];
        count--;
        return value;
    }

    bool empty() const {
        return count == 0;
    }
};

int main() {
    Queue<int> q;
    q.push(5);
    q.push(10);
    q.push(15);
    std::cout << q.pop() << std::endl;
    std::cout << q.pop() << std::endl;

    Quack<std::string> dq;
    dq.push_front("b");
    dq.push_back("c");
    dq.push_front("a");
    std::cout << dq.pop_front() << std::endl;
    std::cout << dq.pop_back() << std::endl;

    return 0;
}
