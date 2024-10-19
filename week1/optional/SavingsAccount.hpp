#pragma once
#include "Account.hpp"

class SavingsAccount : public Account {
    private:
        double interestRate;
    public: 
        SavingsAccount();
        SavingsAccount(double bal, double rate);
        double calculateInterest();
};
