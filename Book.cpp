#include "Book.h"

Book::Book(string t, string a, int p)
    : Publication(t), author(a), pages(p) {}

int Book::getPages() const {
    return pages;
}

string Book::getTitle() const {
    return title;
}

void Book::display() const {
    cout << "Book Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Pages: " << pages << endl;
}