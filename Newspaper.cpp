#include "Newspaper.h"

Newspaper::Newspaper(string n, string d, string e)
    : Publication(n), date(d), edition(e) {}

string Newspaper::getEdition() const {
    return edition;
}

string Newspaper::getName() const {
    return title;
}

void Newspaper::display() const {
    cout << "Newspaper Name: " << title << endl;
    cout << "Date: " << date << endl;
    cout << "Edition: " << edition << endl;
}