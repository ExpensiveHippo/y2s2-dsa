#pragma once
#include "Account.hpp"

class CheckingAccount : public Account {
    private:
        double fee;
    public:
        CheckingAccount();
        CheckingAccount(double bal, double initialFee);
        virtual void credit(double amt) override;
        virtual double debit(double amt) override;
};