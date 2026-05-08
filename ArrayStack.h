#pragma once

#include <iostream>
using namespace std;

template <typename T>
class ArrayStack {
private:
    int top;        // index of top element
    int capacity;   // maximum size
    T* arr;         // dynamic array

public:
    // Constructor
    ArrayStack(int cap = 100) {
        capacity = cap;
        arr = new T[capacity];
        top = -1;
    }

    // Destructor
    ~ArrayStack() {
        delete[] arr;
    }

    // Push element onto stack
    bool push(T value) {
        if (top >= capacity - 1) {
            cout << "Stack Overflow!" << endl;
            return false;
        }
        arr[++top] = value;
        return true;
    }

    // Pop element from stack
    bool pop(T& value) {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return false;
        }
        value = arr[top--];
        return true;
    }

    // Peek top element
    bool peek(T& value) const {
        if (isEmpty()) return false;
        value = arr[top];
        return true;
    }

    // Check if stack is empty
    bool isEmpty() const {
        return top == -1;
    }

    // Get current size
    int size() const {
        return top + 1;
    }

    // Clear stack
    void clear() {
        top = -1;
    }

    // Copy constructor (needed for passing by value)
    ArrayStack(const ArrayStack<T>& other) {
        capacity = other.capacity;
        top = other.top;
        arr = new T[capacity];
        for (int i = 0; i <= top; i++) {
            arr[i] = other.arr[i];
        }
    }

    // Assignment operator
    ArrayStack<T>& operator=(const ArrayStack<T>& other) {
        if (this != &other) {
            delete[] arr;
            capacity = other.capacity;
            top = other.top;
            arr = new T[capacity];
            for (int i = 0; i <= top; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }
};


