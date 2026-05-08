#include <iostream>
using namespace std;

// ---------------- ArrayQueue Class ----------------
template <typename T>
class ArrayQueue {
private:
    int front, rear, capacity, count;
    T* arr;

public:
    ArrayQueue(int cap = 100) {
        capacity = cap;
        arr = new T[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~ArrayQueue() {
        delete[] arr;
    }

    bool enqueue(T value) {
        if (count == capacity) {
            cout << "Queue Overflow!" << endl;
            return false;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        count++;
        return true;
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return -1; // assuming int queue
        }
        T value = arr[front];
        front = (front + 1) % capacity;
        count--;
        return value;
    }

    bool isEmpty() const {
        return count == 0;
    }

    int size() const {
        return count;
    }

    void clear() {
        front = 0;
        rear = -1;
        count = 0;
    }

    // Copy constructor
    ArrayQueue(const ArrayQueue<T>& other) {
        capacity = other.capacity;
        front = other.front;
        rear = other.rear;
        count = other.count;
        arr = new T[capacity];
        for (int i = 0; i < capacity; i++) {
            arr[i] = other.arr[i];
        }
    }

    // Assignment operator
    ArrayQueue<T>& operator=(const ArrayQueue<T>& other) {
        if (this != &other) {
            delete[] arr;
            capacity = other.capacity;
            front = other.front;
            rear = other.rear;
            count = other.count;
            arr = new T[capacity];
            for (int i = 0; i < capacity; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }
};

// ---------------- Recursive Functions ----------------

void copyQueue(ArrayQueue<int>& src, ArrayQueue<int>& copy) {
    if (src.isEmpty()) return;
    int v = src.dequeue();
    copyQueue(src, copy);
    copy.enqueue(v);
}

void display(ArrayQueue<int>& as) {
    if (as.isEmpty()) return;
    int v = as.dequeue();
    cout << v << " ";
    display(as);
}

int getSize(ArrayQueue<int>& as) {
    if (as.isEmpty()) return 0;
    int v = as.dequeue();
    return 1 + getSize(as);
}

int maxRecursive(ArrayQueue<int>& as) {
    int v = as.dequeue();
    if (as.isEmpty()) return v;
    int m = maxRecursive(as);
    return (v > m) ? v : m;
}

void frequencyHelper(ArrayQueue<int>& src, ArrayQueue<int>& freq) {
    if (src.isEmpty()) return;
    int v = src.dequeue();
    int count = 1;

    ArrayQueue<int> temp;
    while (!src.isEmpty()) {
        int x = src.dequeue();
        if (x == v) count++;
        else temp.enqueue(x);
    }

    while (!temp.isEmpty()) {
        int x = temp.dequeue();
        src.enqueue(x);
    }

    freq.enqueue(count);
    frequencyHelper(src, freq);
}

ArrayQueue<int> frequency(ArrayQueue<int> adt) {
    ArrayQueue<int> freq;
    frequencyHelper(adt, freq);
    return freq;
}

// ---------------- MAIN ----------------
int main() {
    ArrayQueue<int> q;
    q.enqueue(4);
    q.enqueue(6);
    q.enqueue(8);
    q.enqueue(6);
    q.enqueue(4);

    cout << "Original queue (display): ";
    ArrayQueue<int> temp1 = q;
    display(temp1);
    cout << endl;

    cout << "Size of queue: ";
    ArrayQueue<int> temp2 = q;
    cout << getSize(temp2) << endl;

    cout << "Max element in queue: ";
    ArrayQueue<int> temp3 = q;
    cout << maxRecursive(temp3) << endl;

    cout << "Copy queue: ";
    ArrayQueue<int> copy;
    ArrayQueue<int> temp4 = q;
    copyQueue(temp4, copy);
    display(copy);
    cout << endl;

    cout << "Frequency queue: ";
    ArrayQueue<int> temp5 = q;
    ArrayQueue<int> freq = frequency(temp5);
    display(freq);
    cout << endl;

    return 0;
}
