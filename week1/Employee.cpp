#include "Employee.hpp"

Employee::Employee() {}

Employee::Employee(
    std::string first,
    std::string last,
    int monthly) : firstName(first),
                   lastName(last),
                   monthlySalary(monthly > 0 ? monthly : 0) {}

void Employee::setFirstName(std::string f) { firstName = f; }

std::string Employee::getFirstName() { return firstName; }

void Employee::setLastName(std::string f) { lastName = f; }

std::string Employee::getLastName() { return lastName; }

void Employee::setMonthlySalary(int s) { monthlySalary = s > 0 ? s : 0; }

int Employee::getMonthlySalary() { return monthlySalary; }
