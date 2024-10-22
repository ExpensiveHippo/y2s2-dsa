#pragma once

#include <string>
#include <iostream>

class Person {
    private:
        std::string name;
        std::string telNo; 

    public:
        Person();
        Person(std::string n, std::string t);

        friend std::ostream& operator<<(std::ostream& out, const Person &p);
        friend bool operator==(const Person& lhs, const Person& rhs);
        void setName(std::string name);      
        std::string getName();
        void setTelNo(std::string num);
        std::string getTelNo();
};