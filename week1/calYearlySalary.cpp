#include <iostream>
#include "Employee.hpp"

using namespace std;

int main() {
    Employee e1("First", "Employee", 36000);
    Employee e2("Second", "Employee", 48000);

    cout << "\nBefore raise\n" << endl;

    cout << e1.getFirstName() + " " + e1.getLastName() + ": "<< 
    e1.getMonthlySalary() << endl;

    cout << e2.getFirstName() + " " + e2.getLastName() + ": "<< 
    e2.getMonthlySalary() << endl;

    e1.setMonthlySalary(e1.getMonthlySalary() * 1.1);
    e2.setMonthlySalary(e2.getMonthlySalary() * 1.1);

    cout << "\nAfter raise\n" << endl;

    cout << e1.getFirstName() + " " + e1.getLastName() + ": "<< 
    e1.getMonthlySalary() << endl;

    cout << e2.getFirstName() + " " + e2.getLastName() + ": "<< 
    e2.getMonthlySalary() << endl;

    return 0;
}