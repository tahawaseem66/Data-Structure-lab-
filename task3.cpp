#include <iostream>
#include "ArrayStack.h"
using namespace std;



void copyStack(ArrayStack<int>& src, ArrayStack<int>& copy) {
    if (src.isEmpty()) return;
    int v;
    src.pop(v);
    copyStack(src, copy);
    copy.push(v);
}

void display(ArrayStack<int>& as) {
    if (as.isEmpty()) return;
    int v;
    as.pop(v);
    cout << v << " ";
    display(as);
}

int getSize(ArrayStack<int>& as) {
    if (as.isEmpty()) return 0;
    int v;
    as.pop(v);
    return 1 + getSize(as);
}

int maxRecursive(ArrayStack<int>& as) {
    int v;
    as.pop(v);
    if (as.isEmpty()) return v;
    int m = maxRecursive(as);
    return (v > m) ? v : m;
}

// Frequency helper
void frequencyHelper(ArrayStack<int>& src, ArrayStack<int>& freq) {
    if (src.isEmpty()) return;
    int v;
    src.pop(v);
    int count = 1;

    ArrayStack<int> temp;
    while (!src.isEmpty()) {
        int x;
        src.pop(x);
        if (x == v) count++;
        else temp.push(x);
    }

    while (!temp.isEmpty()) {
        int x;
        temp.pop(x);
        src.push(x);
    }

    freq.push(count);
    frequencyHelper(src, freq);
}

ArrayStack<int> frequency(ArrayStack<int> adt) {
    ArrayStack<int> freq;
    frequencyHelper(adt, freq);
    return freq;
}

// ---------------- MAIN ----------------
int main() {
    ArrayStack<int> st;
    st.push(3);
    st.push(5);
    st.push(7);
    st.push(5);
    st.push(3);

    cout << "Original stack (display): ";
    ArrayStack<int> temp1 = st;
    display(temp1);
    cout << endl;

    cout << "Size of stack: ";
    ArrayStack<int> temp2 = st;
    cout << getSize(temp2) << endl;

    cout << "Max element in stack: ";
    ArrayStack<int> temp3 = st;
    cout << maxRecursive(temp3) << endl;

    cout << "Copy stack: ";
    ArrayStack<int> copy;
    ArrayStack<int> temp4 = st;
    copyStack(temp4, copy);
    display(copy);
    cout << endl;

    cout << "Frequency stack: ";
    ArrayStack<int> temp5 = st;
    ArrayStack<int> freq = frequency(temp5);
    display(freq);
    cout << endl;

    return 0;
}
