#include <iostream>
using namespace std;

// ---------------- DoublyLinkedList Node ----------------
template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;
    Node(T val) : data(val), prev(nullptr), next(nullptr) {}
};

// ---------------- ConcreteDoublyLinkedList Class ----------------
template <typename T>
class ConcreteDoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    ConcreteDoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~ConcreteDoublyLinkedList() {
        while (!isEmpty()) {
            int v;
            removeFromFirst(v);
        }
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void insertAtFirst(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (isEmpty()) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    bool removeFromFirst(T& val) {
        if (isEmpty()) return false;
        Node<T>* temp = head;
        val = temp->data;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
        return true;
    }

    bool removeFromLast(T& val) {
        if (isEmpty()) return false;
        Node<T>* temp = tail;
        val = temp->data;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
        return true;
    }
};

// ---------------- Recursive Functions ----------------

void LLCopy(ConcreteDoublyLinkedList<int>& src, ConcreteDoublyLinkedList<int>& copy) {
    if (src.isEmpty()) return;
    int x;
    src.removeFromLast(x);
    LLCopy(src, copy);
    copy.insertAtFirst(x);
}

void display(ConcreteDoublyLinkedList<int>& list) {
    if (list.isEmpty()) return;
    int v;
    list.removeFromFirst(v);
    cout << v << " -> ";
    display(list);
}

int getSize(ConcreteDoublyLinkedList<int>& list) {
    if (list.isEmpty()) return 0;
    int v;
    list.removeFromLast(v);
    return 1 + getSize(list);
}

int maxRecursive(ConcreteDoublyLinkedList<int>& list) {
    int v;
    list.removeFromLast(v);
    if (list.isEmpty()) return v;
    int m = maxRecursive(list);
    return (v > m) ? v : m;
}

void frequencyHelper(ConcreteDoublyLinkedList<int>& src, ConcreteDoublyLinkedList<int>& freq) {
    if (src.isEmpty()) return;
    int v;
    src.removeFromLast(v);
    int count = 1;

    ConcreteDoublyLinkedList<int> temp;
    while (!src.isEmpty()) {
        int x;
        src.removeFromLast(x);
        if (x == v) count++;
        else temp.insertAtFirst(x);
    }

    while (!temp.isEmpty()) {
        int x;
        temp.removeFromLast(x);
        src.insertAtFirst(x);
    }

    freq.insertAtFirst(count);
    frequencyHelper(src, freq);
}

ConcreteDoublyLinkedList<int> frequency(ConcreteDoublyLinkedList<int> list) {
    ConcreteDoublyLinkedList<int> freq;
    frequencyHelper(list, freq);
    return freq;
}

// ---------------- MAIN ----------------
int main() {
    ConcreteDoublyLinkedList<int> dll;
    dll.insertAtFirst(2);
    dll.insertAtFirst(4);
    dll.insertAtFirst(6);
    dll.insertAtFirst(4);
    dll.insertAtFirst(2);

    cout << "Original list (display): ";
    ConcreteDoublyLinkedList<int> temp1 = dll;
    display(temp1);
    cout << endl;

    cout << "Size of list: ";
    ConcreteDoublyLinkedList<int> temp2 = dll;
    cout << getSize(temp2) << endl;

    cout << "Max element in list: ";
    ConcreteDoublyLinkedList<int> temp3 = dll;
    cout << maxRecursive(temp3) << endl;

    cout << "Copy list: ";
    ConcreteDoublyLinkedList<int> copy;
    ConcreteDoublyLinkedList<int> temp4 = dll;
    LLCopy(temp4, copy);
    display(copy);
    cout << endl;

    cout << "Frequency list: ";
    ConcreteDoublyLinkedList<int> temp5 = dll;
    ConcreteDoublyLinkedList<int> freq = frequency(temp5);
    display(freq);
    cout << endl;

    return 0;
}
 