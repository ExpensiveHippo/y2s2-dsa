#pragma once

class Account {
    private:
        double balance;
    public:
        Account();
        Account(double bal);
        virtual void credit(double amt);
        virtual double debit(double amt);
        double getBalance();
};