#include "Library.h"

void Library::addBook(const Book& book) {
    books.push_back(book);
}

void Library::addNewspaper(const Newspaper& newspaper) {
    newspapers.push_back(newspaper);
}

void Library::displayCollection() const {
    cout << "\n--- Books ---\n";
    for (const auto& book : books) {
        book.display();
        cout << endl;
    }

    cout << "--- Newspapers ---\n";
    for (const auto& paper : newspapers) {
        paper.display();
        cout << endl;
    }
}

void Library::sortBooksByPages() {
    sort(books.begin(), books.end(),
        [](const Book& a, const Book& b) {
            return a.getPages() < b.getPages();
        });
}

void Library::sortNewspapersByEdition() {
    sort(newspapers.begin(), newspapers.end(),
        [](const Newspaper& a, const Newspaper& b) {
            return a.getEdition() < b.getEdition();
        });
}

Book* Library::searchBookByTitle(string t) {
    for (auto& book : books) {
        if (book.getTitle() == t)
            return &book;
    }
    return nullptr;
}

Newspaper* Library::searchNewspaperByName(string n) {
    for (auto& paper : newspapers) {
        if (paper.getName() == n)
            return &paper;
    }
    return nullptr;
}