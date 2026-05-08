#include <iostream>
using namespace std;

// Recursive functions from Task 2

void func(int n) {
    if (n <= 0) return;
    cout << n << endl;
    func(n - 1);
}

int sum(int n) {
    if (n <= 0) return 0;
    return n + sum(n - 1);
}

int maxRecursive(int a[], int size) {
    if (size == 1) return a[0];
    int m = maxRecursive(a, size - 1);
    return (a[size - 1] > m) ? a[size - 1] : m;
}

int countDigits(int n) {
    if (n == 0) return 0;
    int count = (n % 10 != 0) ? 1 : 0;
    return count + countDigits(n / 10);
}

void displayDigits(int n) {
    if (n == 0) return;
    cout << n % 10 << " ";
    displayDigits(n / 10);
}

int binarySearch(int a[], int low, int high, int v) {
    if (low > high) return -1;
    int mid = (low + high) / 2;
    if (a[mid] == v) return mid;
    else if (v > a[mid]) return binarySearch(a, mid + 1, high, v);
    else return binarySearch(a, low, mid - 1, v);
}

// ---------------- MAIN ----------------
int main() {
    cout << "Testing func(n):" << endl;
    func(5);  // prints 5 4 3 2 1

    cout << "\nTesting sum(n):" << endl;
    cout << "Sum of 10 = " << sum(10) << endl;

    cout << "\nTesting maxRecursive:" << endl;
    int arr[] = { 3, 7, 2, 9, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Max = " << maxRecursive(arr, size) << endl;

    cout << "\nTesting countDigits:" << endl;
    cout << "Count digits in 102030 = " << countDigits(102030) << endl;

    cout << "\nTesting displayDigits:" << endl;
    cout << "Digits of 12345: ";
    displayDigits(12345);
    cout << endl;

    cout << "\nTesting binarySearch:" << endl;
    int sortedArr[] = { 1, 3, 5, 7, 9, 11 };
    int n = sizeof(sortedArr) / sizeof(sortedArr[0]);
    int target = 7;
    int index = binarySearch(sortedArr, 0, n - 1, target);
    if (index != -1)
        cout << "Found " << target << " at index " << index << endl;
    else
        cout << target << " not found" << endl;

    return 0;
}
