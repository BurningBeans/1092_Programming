#include <iostream>
#include "Account.h"
#include "SavingAccount.h"
#include "CheckingAccount.h"
using namespace std;
bool CheckingToSaving(CheckingAccount&, SavingAccount&, const double);
bool SavingToChecking(SavingAccount&, CheckingAccount&, const double);
int main()
{
    cout << "\nCreating a saving account" << endl;
    SavingAccount sAcnt(300.0, 0.05);
    sAcnt.print();
    sAcnt.debit(50.0);
    cout << " New balance after withdrawing $50 from the saving account: " << sAcnt.getBalance() << endl;
    sAcnt.credit(150.0);
    cout << " New balance after deposting $150 to the saving account: " << sAcnt.getBalance() << endl;
    sAcnt.print();
    cout << " Interest of the saving account: " << sAcnt.calculateInterest() << endl;
    cout << " New balance after adding interest: " << sAcnt.getBalance() << endl;
    cout << " Withdraw 800 for the saving account: " << endl;
    sAcnt.debit(800);
    cout << "\nCreat a checking account." << endl;
    CheckingAccount cAcnt(400.0, 0.02);
    cAcnt.print();
    cAcnt.debit(200.0);
    cout << " New balance after withdrawing $200 from the checking account: " << cAcnt.getBalance() << endl;
    cAcnt.credit(150.0);
    cout << " New balance after deposting $150 to the checking account: " << cAcnt.getBalance() << endl;

    cout << endl;
    cAcnt.print();
    sAcnt.print();

    cout << "\nAfter transfer $600 from cAcnt to sAcnt: " << endl;
    CheckingToSaving(cAcnt, sAcnt, 600.0);
    cout << "New balance of cAcnt: " << cAcnt.getBalance() << " New balance of sAcnt: " << sAcnt.getBalance() << endl;
    cout << "\nAfter transfer $800 from sAcnt to cAcnt: " << endl;
    SavingToChecking(sAcnt, cAcnt, 800.0);
    cout << "New balance of cAcnt: " << cAcnt.getBalance() << " New balance of sAcnt: " << sAcnt.getBalance() << endl;
    CheckingToSaving(cAcnt, sAcnt, 50.0);
    cout << "\nAfter transfer $50 from cAcnt to sAcnt: " << endl;
    cout << "New balance of cAcnt: " << cAcnt.getBalance() << " New balance of sAcnt: " << sAcnt.getBalance() << endl;
    SavingToChecking(sAcnt, cAcnt, 50.0);
    cout << "\nAfter transfer $50 from sAcnt to cAcnt: " << endl;
    cout << "New balance of cAcnt: " << cAcnt.getBalance() << " New balance of sAcnt: " << sAcnt.getBalance() << endl;
    system("pause");
    return 0;
}
bool CheckingToSaving(CheckingAccount& cAcnt, SavingAccount& sAcnt, const double amount)
{
    if(cAcnt.balance-(amount+cAcnt.transactFeeW) >=0 )
    {
        cAcnt.balance = cAcnt.balance-(amount+cAcnt.transactFeeW);
        sAcnt.credit(amount);
        return true;
    }
    else
    {
        cout << "Transfer transaction fails.\n";
        return false;
    }
    return false;
}
bool SavingToChecking(SavingAccount& sAcnt, CheckingAccount& cAcnt, const double amount)
{
    if(sAcnt.balance-(amount+sAcnt.transactFee) >=0 )
    {
        sAcnt.balance = sAcnt.balance-(amount+sAcnt.transactFee);
        cAcnt.credit(amount);
        return true;
    }
    else
    {
        cout << "Transfer transaction fails.\n";
        return false;
    }
    return false;
}
//g++ main.cpp Account.cpp SavingAccount.cpp CheckingAccount.cpp