#pragma once


#include "Publication.h"

class Newspaper : public Publication {
private:
    string date;
    string edition;

public:
    Newspaper(string name, string date, string edition);

    string getEdition() const;
    string getName() const;

    void display() const override;
};


