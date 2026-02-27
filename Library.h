#pragma once


#include <vector>
#include <algorithm>
#include "Book.h"
#include "Newspaper.h"

class Library {
private:
    vector<Book> books;
    vector<Newspaper> newspapers;

public:
    void addBook(const Book& book);
    void addNewspaper(const Newspaper& newspaper);

    void displayCollection() const;

    void sortBooksByPages();
    void sortNewspapersByEdition();

    Book* searchBookByTitle(string title);
    Newspaper* searchNewspaperByName(string name);
};


