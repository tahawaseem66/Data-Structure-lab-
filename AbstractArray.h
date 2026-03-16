#pragma once
#ifndef ABSTRACTARRAY_H
#define ABSTRACTARRAY_H

#include <iostream>
using namespace std;

class AbstractArray
{
public:
    AbstractArray(int _maxCapacity = 0);
    AbstractArray(const AbstractArray& AA);

    virtual void add(int v) = 0;
    virtual bool remove(int& value) = 0;
    virtual bool get(int index, int& value) = 0;
    virtual void insert(int index, int value) = 0;

    bool isEmpty();
    bool isFull();

protected:
    int currentIndex;
    int* values;
    int maxCapacity;
};

// constructor
AbstractArray::AbstractArray(int _maxCapacity)
{
    currentIndex = -1;
    maxCapacity = _maxCapacity;
    values = new int[maxCapacity] {0};
}

// copy constructor
AbstractArray::AbstractArray(const AbstractArray& AA)
{
    maxCapacity = AA.maxCapacity;
    values = new int[maxCapacity] {0};

    /*
    for(int i = 0; i < maxCapacity; i++)
    {
        values[i] = AA.values[i];
    }
    */
}

// check empty
bool AbstractArray::isEmpty()
{
    return (currentIndex < 0);
}

// check full
bool AbstractArray::isFull()
{
    return (currentIndex == maxCapacity - 1);
}

#endif
