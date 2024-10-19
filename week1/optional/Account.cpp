#include <iostream>
#include "Account.hpp"

Account::Account() { }

Account::Account(double b) : balance(b < 0 ? 0 : b) {
    if (b < 0) {
        std::cout << "Initial balance was invalid." << std::endl;
    }
}

void Account::credit(double a) { 
    if (a > 0) {
        balance += a; 
    }
}

double Account::debit(double a) { 
    if (a <= balance) {
        balance -= a;
        return a;
    } 
    std::cout << "Debit amount exceeded account balance" << std::endl;
    return 0;
}

double Account::getBalance() { return balance; }

