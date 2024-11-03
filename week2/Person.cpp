#include "Person.hpp"

#include <string>

Person::Person() {}
Person::Person(std::string n, std::string t) : name(n), telNo(t) {}

std::ostream &operator<<(std::ostream &out, const Person &p)
{
    return out << const_cast<Person &>(p).getName() << ": "
               << const_cast<Person &>(p).getTelNo() << std::endl;
}

bool operator==(const Person &lhs, const Person &rhs)
{
    return const_cast<Person &>(lhs).getTelNo() == const_cast<Person &>(rhs).getTelNo();
}

void Person::setName(std::string newName)
{
    name = newName;
}

std::string Person::getName()
{
    return name;
}

void Person::setTelNo(std::string newTelNo)
{
    telNo = newTelNo;
}

std::string Person::getTelNo()
{
    return telNo;
}