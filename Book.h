#pragma once

#include "Publication.h"

class Book : public Publication {
private:
    string author;
    int pages;

public:
    Book(string title, string author, int pages);

    int getPages() const;
    string getTitle() const;

    void display() const override;
};


