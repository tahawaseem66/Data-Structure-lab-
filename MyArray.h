#pragma once
#ifndef MYARRAY_H
#define MYARRAY_H

#include "AbstractArray.h"

class MyArray : public AbstractArray
{
public:
    MyArray(int _currentIndex = 0) : AbstractArray(_currentIndex) {}
    MyArray(const MyArray& ma) : AbstractArray(ma) {}

    void add(int v);
    bool remove(int& v);
    bool get(int index, int& v);
    void insert(int index, int value);
};

// add value
void MyArray::add(int v)
{
    if (!isFull())
    {
        values[++currentIndex] = v;
        return;
    }

    cout << "Array is full\n";
}

// remove value
bool MyArray::remove(int& v)
{
    if (!isEmpty())
    {
        v = values[currentIndex--];
        return true;
    }

    return false;
}

// get value
bool MyArray::get(int index, int& v)
{
    if (index >= 0 && index <= currentIndex)
    {
        v = values[index];
        return true;
    }

    return false;
}

// insert value
void MyArray::insert(int index, int value)
{
    if (index >= 0 && index <= currentIndex)
    {
        values[index] = value;
        return;
    }

    cout << index << " is invalid\n";
}

#endif
