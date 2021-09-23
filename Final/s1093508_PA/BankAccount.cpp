#include "BankAccount.h"
#include <iostream>
#include <iomanip>
const double baseAccount::baseIntrsRate = 0.01;
int baseAccount::numOfAccount = 0;
baseAccount::baseAccount(int accN, string lastN, string firstN, string cityN, int bal)
//:accountNumber(accN),lastName(lastN),firstName(firstN),cityName(cityN),balance(bal)
{
    setAccountNumber(accN);
    setLastName(lastN);
    setFirstName(firstN);
    setCityName(cityN);
    setBalance(bal);
    incNumOfAccount();
}
void baseAccount::setAccountNumber(int accN)
{
    accountNumber = accN;
}
int baseAccount::getAccountNumber() const
{
    return accountNumber;
}

void baseAccount::setLastName(string lastN)
{
    lastName = lastN;
}
string baseAccount::getLastName() const
{
    return lastName;
}

void baseAccount::setFirstName(string firstN)
{
    firstName = firstN;
}
string baseAccount::getFirstName() const
{
    return firstName;
}

void baseAccount::setCityName(string cityN)
{
    cityName = cityN;
}
string baseAccount::getCityName() const
{
    return cityName;
}

void baseAccount::setBalance(int bal)
{
    balance = bal;
}
int baseAccount::getBalance() const
{
    return balance;
}
void baseAccount::incNumOfAccount()
{
    numOfAccount++;
}
int baseAccount::getNumOfAccount()
{
    return numOfAccount;
}
void baseAccount::printAccount() const
{
    cout << left << setw(10) << getAccountNumber() << setw(16) << getLastName() << setw(11) << getFirstName() << setw(18) << getCityName()
         << right << setw(10) << getBalance();
}

//----------------------------------------------------------------
int savingAccount::numOfAccount = 0; 
savingAccount::savingAccount(int accN, string lastN, string firstN, string cityN, int bal, double interestR)
:baseAccount(accN, lastN, firstN, cityN, bal)//, floatingIntrsRate(interestR)
{
    setFloatingIntrsRate(interestR);
}
void savingAccount::setFloatingIntrsRate(double interestR)
{
    floatingIntrsRate = interestR;
}
double savingAccount::getFloatingIntrsRate() const
{
    return floatingIntrsRate;
}
void savingAccount::printAccount() const
{
    baseAccount::printAccount();
    cout << setw(15) << getFloatingIntrsRate() << endl;
}
int savingAccount::calculateIntrs()
{
    if (getBalance() > 10000)
    {
        setBalance(getBalance() + ( 10000 * baseIntrsRate + (getBalance() - 100000) * (baseIntrsRate + floatingIntrsRate)));
        return 10000 * baseIntrsRate + (getBalance() - 100000) * (baseIntrsRate + floatingIntrsRate);
    }
    else
    {
        setBalance(getBalance()+((baseIntrsRate + floatingIntrsRate) * getBalance()));
        return (baseIntrsRate + floatingIntrsRate) * getBalance();
    }
}
void savingAccount::incNumOfAccount()
{
    numOfAccount++;
}
int savingAccount::getNumOfAccount()
{
    return numOfAccount;
}
//----------------------------------------------------------------
int checkingAccount::numOfAccount = 0;
checkingAccount::checkingAccount(int accN, string lastN, string firstN, string cityN, int bal)
:baseAccount(accN, lastN, firstN, cityN, bal)
{
}
void checkingAccount::printAccount() const
{
    baseAccount::printAccount();
    cout << endl;
}
int checkingAccount::calculateIntrs()
{
    setBalance(getBalance()+(getBalance()* baseIntrsRate));
    return getBalance() * baseIntrsRate;
}
void checkingAccount::incNumOfAccount()
{
    numOfAccount++;
}
int checkingAccount::getNumOfAccount()
{
    return numOfAccount;
}