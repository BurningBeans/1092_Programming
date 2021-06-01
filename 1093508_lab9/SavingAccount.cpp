#include <iostream>
#include "SavingAccount.h"
using namespace std;
SavingAccount::SavingAccount(double bal, double iRate, double transF)
{
    if (bal > 0)
        balance = bal;
    else
        balance = 0;
    if (iRate > 0)
        interestRate = iRate;
    else
        interestRate = 0;
    if (transF > 0)
        transactFee = transF;
    else
        transactFee = 0;
}
// parameters: balance, interest rate, transaction fee.
bool SavingAccount::debit(double withdw)
{
    if (withdw > 0 && (withdw + transactFee) <= balance)
    {
        balance = balance - (withdw + transactFee);
        return true;
    }
    else if (withdw > balance || (withdw + transactFee) > balance)
    {
        cout << " Debit amount exceeded account balance." << endl;
        return false;
    }
    return false;
}
void SavingAccount::print()
{
    cout << "Saving Account: " << endl;
    cout << " Balance: " << balance << endl;
    cout << " Interest rate: " << interestRate << endl;
    cout << " Transaction fee of withdraw: " << transactFee << endl;
}