#include "CheckingAccount.hpp"

CheckingAccount::CheckingAccount() { }

CheckingAccount::CheckingAccount(double b, double f) : Account(b) {
    fee = f;
}

void CheckingAccount::credit(double a) {
    if (a > 0) {
        Account::credit(a - fee);
    }
}

double CheckingAccount::debit(double a) {
    int amt = Account::debit(a);
    
    if (amt != 0) {
        // if money was withdrawn, pay fee
        Account::debit(fee);

        // add further logic if insufficient for fee
        // or just deduct from withdrawn amt
    }
    return amt;
}