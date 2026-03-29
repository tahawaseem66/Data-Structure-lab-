#include <iostream>
using namespace std;

#include "Stack.h"
#include "MyStack.h"
#include "Queue.h"
#include "MyQueue.h"

/***** GLOBAL FUNCTION PROTOTYPES *****/
void readStack(MyStack& S, int n);
void readQueue(MyQueue& Q, int n);

/***** MAIN FUNCTION *****/
int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;

    // ================= STACK PART =================
    cout << "\n--- STACK CALCULATION ---\n";

    MyStack S(n);
    readStack(S, n);

    // Create temp stack to preserve data
    MyStack temp(n);

    int value;

    // Move all elements to temp (reverse order)
    while (!S.isEmpty())
    {
        S.pop(value);
        temp.push(value);
    }

    // Now use temp for calculation AND restore S
    int sum = 0, count = 0;

    temp.pop(value);
    int max = value;
    int min = value;
    sum = value;
    count = 1;

    S.push(value); // restore

    while (!temp.isEmpty())
    {
        temp.pop(value);

        sum += value;
        if (value > max) max = value;
        if (value < min) min = value;

        count++;
        S.push(value); // restore original stack
    }

    cout << "Average: " << (float)sum / count << endl;
    cout << "Maximum: " << max << endl;
    cout << "Minimum: " << min << endl;


    // ================= QUEUE PART =================
    cout << "\n--- QUEUE CALCULATION ---\n";

    MyQueue Q(n);
    readQueue(Q, n);

    // Copy Queue
    MyQueue CQ = Q;

    int sumQ = 0, countQ = 0;

    int val = CQ.dequeue();
    int maxQ = val;
    int minQ = val;
    sumQ = val;
    countQ = 1;

    while (!CQ.isEmpty())
    {
        val = CQ.dequeue();
        sumQ += val;

        if (val > maxQ) maxQ = val;
        if (val < minQ) minQ = val;

        countQ++;
    }

    cout << "Average: " << (float)sumQ / countQ << endl;
    cout << "Maximum: " << maxQ << endl;
    cout << "Minimum: " << minQ << endl;

    return 0;
}

/***** FUNCTIONS *****/

void readStack(MyStack& S, int n)
{
    int val;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> val;
        S.push(val);
    }
}

void readQueue(MyQueue& Q, int n)
{
    int val;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> val;
        Q.enqueue(val);
    }
}