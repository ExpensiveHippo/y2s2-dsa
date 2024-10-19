#include "SavingsAccount.hpp"

SavingsAccount::SavingsAccount() { }

SavingsAccount::SavingsAccount(double b, double i) : Account(b) { interestRate = i; }

double SavingsAccount::calculateInterest() { 
    return interestRate * Account::getBalance(); 
}