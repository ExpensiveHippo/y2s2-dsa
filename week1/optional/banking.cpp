#include <iostream>
#include <vector>

#include "Account.hpp"
#include "SavingsAccount.hpp"
#include "CheckingAccount.hpp"

using namespace std;

int main() {
    // init accounts
    vector<Account*> vecAccounts;
    Account normal(10000);
    SavingsAccount saving(10000, 3 / 100.0);
    CheckingAccount checking(10000, 2.5);    

    vecAccounts.push_back(&normal);
    vecAccounts.push_back(&saving);
    vecAccounts.push_back(&checking);

    for (int i = 0, j = vecAccounts.size(); i < j; i++) {
        double dAmt, cAmt;

        // Beginning value
        Account* acc = vecAccounts[i];
        cout << "Account " << i+1 << endl;
        cout << "Balance ($): " << acc->getBalance() << endl; 

        // Debit function
        cout << "\nAmount to withdraw ($): " << flush;
        cin >> dAmt;
        acc->debit(dAmt);
        cout << "\nAfter withdrawal ($): " << acc->getBalance() << endl;
        
        // Credit function
        cout << "\nAmount to deposit ($): " << flush;
        cin >> cAmt;
        acc->credit(cAmt);
        cout << "\nAfter deposit ($): " << acc->getBalance() << endl;

        // Check if account type is Savings
        SavingsAccount* isSaving = dynamic_cast <SavingsAccount*>(acc);
        if (isSaving) {
            double interest = isSaving->calculateInterest();
            isSaving->credit(interest);
        }

        // End value
        cout << "\nUpdated balance ($): " << acc->getBalance() << "\n\n" << endl; 
    }
    return 0;
}