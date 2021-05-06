#include <iostream>
#include "CheckingAccount.h"
using namespace std;
CheckingAccount::CheckingAccount(double bal, double iRate, double transFW, double transFD)
{
    if (bal >0)
        balance = bal;
    else
        balance = 0;
    if(iRate >0)
        interestRate = iRate;
    else
        interestRate = 0;
    if (transFW > 0)
        transactFeeW = transFW;
    else
        transactFeeW = 0;
    if(transFD > 0)
        transactFeeD = transFD;
    else
        transactFeeD = 0;
}
// Parameters: balance, interest rate, transaction fee for withdraw, transaction fee for deposition
bool CheckingAccount::debit(double withdw)
{
    if(withdw > 0 && (withdw+transactFeeW) <= balance)
    {
        balance = balance - (withdw+transactFeeW);
        return true;
    }
    else if(withdw > balance || (withdw+transactFeeW) > balance)
    {
        cout << " Debit amount exceeded account balance." << endl;
        return false;
    }
    return false;
} // return true if it can be done successfully
void CheckingAccount::credit(double bal)
{
    balance +=bal;
    balance -= transactFeeD;
}
void CheckingAccount::print()
{
    cout << "Checking Account: " <<endl;
    cout << " Balance: " << balance << endl;
    cout << " Interest rate: " << interestRate << endl;
    cout << " Transaction fee of withdraw: " << transactFeeW << endl;
    cout << " Transcation fee of deposition: " << transactFeeD << endl;
}