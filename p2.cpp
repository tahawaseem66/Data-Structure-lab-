#include <iostream>
using namespace std;
#include<string>
#include "Stack.h"
#include "MyStack.h"
#include "Queue.h"
#include "MyQueue.h"

/***** FUNCTION PROTOTYPES *****/
void stackSolution();
void queueSolution();

/***** MAIN *****/
int main()
{
    stackSolution();   // first stack
    queueSolution();   // then queue
    return 0;
}

/*************** STACK SOLUTION ****************/
void stackSolution()
{
    cout << "\n--- STACK SOLUTION ---\n";

    string sentence;

    cout << "Enter sentence (end with .): ";
    getline(cin, sentence);   // ✅ NO ignore needed here (first input)

    int n = sentence.length();
    MyStack S(n);

    // push characters (cast to int)
    for (int i = 0; i < n; i++)
        S.push((int)sentence[i]);

    // Character count
    cout << "Characters: " << n << endl;

    // Word count
    int words = 0;
    for (int i = 0; i < n; i++)
        if (sentence[i] == ' ')
            words++;
    words++;
    cout << "Words: " << words << endl;

    // Word Reverse
    cout << "Word Reverse: ";

    char ch;
    string word = "";

    while (!S.isEmpty())
    {
        int temp;
        S.pop(temp);
        ch = (char)temp;

        if (ch == ' ' || ch == '.')
        {
            cout << word << " ";
            word = "";
        }
        else
        {
            word = ch + word;
        }
    }
    cout << "." << endl;

    // Frequency
    cout << "\nWord Frequencies (Stack):\n";

    for (int i = 0; i < n; )
    {
        string w = "";

        while (i < n && sentence[i] != ' ' && sentence[i] != '.')
        {
            w += sentence[i];
            i++;
        }

        int count = 0;

        for (int j = 0; j < n; )
        {
            string tempWord = "";

            while (j < n && sentence[j] != ' ' && sentence[j] != '.')
            {
                tempWord += sentence[j];
                j++;
            }

            if (w == tempWord)
                count++;

            j++;
        }

        cout << w << " " << count << endl;
        i++;
    }
}


/*************** QUEUE SOLUTION ****************/
void queueSolution()
{
    cout << "\n--- QUEUE SOLUTION ---\n";

    string sentence;

    cout << "Enter sentence (end with .): ";
    getline(cin, sentence);  // ✅ works fine (no cin before)

    int n = sentence.length();
    MyQueue Q(n);

    // enqueue characters
    for (int i = 0; i < n; i++)
        Q.enqueue((int)sentence[i]);

    // Character count
    cout << "Characters: " << n << endl;

    // Word count
    int words = 0;
    for (int i = 0; i < n; i++)
        if (sentence[i] == ' ')
            words++;
    words++;
    cout << "Words: " << words << endl;

    // Word Reverse
    cout << "Word Reverse: ";

    string word = "";

    for (int i = 0; i < n; i++)
    {
        char ch = sentence[i];

        if (ch == ' ' || ch == '.')
        {
            cout << word << " ";
            word = "";
        }
        else
        {
            word = ch + word;
        }
    }
    cout << "." << endl;

    // Frequency
    cout << "\nWord Frequencies (Queue):\n";

    for (int i = 0; i < n; )
    {
        string w = "";

        while (i < n && sentence[i] != ' ' && sentence[i] != '.')
        {
            w += sentence[i];
            i++;
        }

        int count = 0;

        for (int j = 0; j < n; )
        {
            string tempWord = "";

            while (j < n && sentence[j] != ' ' && sentence[j] != '.')
            {
                tempWord += sentence[j];
                j++;
            }

            if (w == tempWord)
                count++;

            j++;
        }

        cout << w << " " << count << endl;
        i++;
    }
}