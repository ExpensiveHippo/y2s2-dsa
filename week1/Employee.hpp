#pragma once

#include <string>

class Employee
{
private:
    std::string firstName;
    std::string lastName;
    int monthlySalary;

public:
    Employee();
    Employee(std::string, std::string, int);
    void setFirstName(std::string);
    std::string getFirstName();
    void setLastName(std::string);
    std::string getLastName();
    void setMonthlySalary(int);
    int getMonthlySalary();
};