#include <iostream>
#include <typeinfo>
#include <vector>
#include "Account.h"
#include "SavingAccount.h"
#include "CheckingAccount.h"
using namespace std;
bool CheckingToSaving(CheckingAccount &, SavingAccount &, const double);
bool SavingToChecking(SavingAccount &, CheckingAccount &, const double);
int main()
{
    //-------------------------------Part 1-------------------------------
    Account bAcnt(100.0);
    SavingAccount sAcnt(110.0, 0.05);
    bAcnt = sAcnt;
    CheckingAccount cAcnt(120.0, 0.02, 4.0, 2.0);
    CheckingAccount c2Acnt(500.0, 0.025, 4.0, 2.0);
    SavingAccount s2Acnt(1000.0, 0.04, 1.0);
    const int numAcc = 5;
    //-------------------------------Adding code here
    vector<Account *> baseAccount(numAcc);
    //-------------------------------
    baseAccount[0] = &cAcnt;
    baseAccount[1] = &c2Acnt;
    baseAccount[2] = &bAcnt;
    baseAccount[3] = &sAcnt;
    baseAccount[4] = &s2Acnt;
    for (int i = 0; i < numAcc; i++)
    {
        cout << "\nAccount type = " << typeid(*baseAccount[i]).name() << endl;
        baseAccount[i]->debit(20.0);
        baseAccount[i]->credit(100.0);
        baseAccount[i]->print();
        //-------------------------------code here
        Account *cAcntPtr = dynamic_cast<CheckingAccount *>(baseAccount[i]);
        //-------------------------------
        if (cAcntPtr != 0)
        {
            cAcntPtr->calculateInterest();
            cout << "Balance of the checking account after adding interest = " << cAcntPtr->getBalance() << endl;
        }
        else
        {
            //-------------------------------code here
            Account *sAcntPtr = dynamic_cast<SavingAccount *>(baseAccount[i]);
            //-------------------------------
            if (sAcntPtr != 0)
            {
                sAcntPtr->calculateInterest();
                cout << "Balance of the saving account after adding interest = " << sAcntPtr->getBalance() << endl;
            }
            else
            {
                cout << "A base account, balance = " << baseAccount[i]->getBalance() << endl;
            }
        }
    }
    //-------------------------------Part 1 end-------------------------------

/*     //-------------------------------Part 2-------------------------------
    SavingAccount sAcnt(110.0, 0.05);
    CheckingAccount cAcnt(120.0, 0.02, 4.0, 2.0);
    CheckingAccount c2Acnt(500.0, 0.025, 4.0, 2.0);
    SavingAccount s2Acnt(1000.0, 0.04, 1.0);
    Account bAcnt(100.0);
    const int numAcc = 4;
    vector<Account *> baseAccount(numAcc);
    baseAccount[0] = &sAcnt;
    baseAccount[1] = &cAcnt;
    baseAccount[2] = &c2Acnt;
    baseAccount[3] = &s2Acnt;
    for (int i = 0; i < numAcc; i++)
    {
        baseAccount[i]->debit(10.0);
        baseAccount[i]->credit(50.0);
        baseAccount[i]->print();
        SavingAccount *sAcntPtr = dynamic_cast<SavingAccount *>(baseAccount[i]);
        if (sAcntPtr != 0)
        {
            sAcntPtr->calculateInterest();
            cout << "Balance of the saving account after adding interest = " << sAcntPtr->getBalance() << endl;
        }
    }
    //-------------------------------Part 2 end------------------------------- */
}
bool CheckingToSaving(CheckingAccount &cAcnt, SavingAccount &sAcnt, const double amount)
{
    if (cAcnt.balance - (amount + cAcnt.transactFeeW) >= 0)
    {
        cAcnt.balance = cAcnt.balance - (amount + cAcnt.transactFeeW);
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
bool SavingToChecking(SavingAccount &sAcnt, CheckingAccount &cAcnt, const double amount)
{
    if (sAcnt.balance - (amount + sAcnt.transactFee) >= 0)
    {
        sAcnt.balance = sAcnt.balance - (amount + sAcnt.transactFee);
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