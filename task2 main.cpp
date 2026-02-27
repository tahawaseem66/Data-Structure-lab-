#include <iostream>
#include "FullTimeEmployee.h"
#include "PartTimeEmployee.h"

using namespace std;

int main() {
    FullTimeEmployee fullTime(50000);      // Fixed salary
    PartTimeEmployee partTime(120, 20);    // 120 hours, $20 per hour

    cout << "Full-Time Employee Salary: $"
        << fullTime.calculateSalary() << endl;

    cout << "Part-Time Employee Salary: $"
        << partTime.calculateSalary() << endl;

    return 0;
}