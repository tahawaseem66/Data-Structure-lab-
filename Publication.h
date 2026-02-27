#pragma once


#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string title;

public:
    Publication(string t);
    virtual void display() const = 0;   // Pure virtual function
    virtual ~Publication();
};
