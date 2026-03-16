#include <iostream>
using namespace std;

#include "AbstractArray.h"
#include "MyArray.h"

void read(AbstractArray* A, istream& in)
{
    int value;

    while (!A->isFull())
    {
        cout << "Enter value: ";
        in >> value;
        A->add(value);
    }
}

void display(AbstractArray* A, ostream& out)
{
    int value;
    int i = 0;

    while (A->get(i, value))
    {
        out << value << " ";
        i++;
    }

    out << endl;
}

void copy(AbstractArray* src, AbstractArray* dst)
{
    int value;
    int i = 0;

    while (src->get(i, value))
    {
        dst->add(value);
        i++;
    }
}

void insert(AbstractArray* src, AbstractArray* dst, int pos)
{
    int value;
    int temp;
    int i = pos;

    // find end of dst
    while (dst->get(i, temp))
        i++;

    // shift dst elements right
    while (i > pos)
    {
        dst->get(i - 1, temp);
        dst->insert(i, temp);
        i--;
    }

    // insert src elements
    int j = 0;
    while (src->get(j, value))
    {
        dst->insert(pos, value);
        pos++;
        j++;
    }
}

void shiftLeft(AbstractArray* aa, int pos)
{
    int value;
    int i = pos;

    while (aa->get(i + 1, value))
    {
        aa->insert(i, value);
        i++;
    }
}

void shiftRight(AbstractArray* aa, int pos)
{
    int value;
    int i = pos;

    while (aa->get(i, value))
        i++;

    while (i > pos)
    {
        aa->get(i - 1, value);
        aa->insert(i, value);
        i--;
    }
}

void stats(AbstractArray* AA, int& max, float& average)
{
    int value;
    int i = 0;
    int sum = 0;
    int count = 0;

    max = -99999;

    while (AA->get(i, value))
    {
        sum += value;

        if (value > max)
            max = value;

        count++;
        i++;
    }

    if (count > 0)
        average = (float)sum / count;
}