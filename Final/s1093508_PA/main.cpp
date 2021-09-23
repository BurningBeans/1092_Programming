// Fig. 17.7: Fig17_7.cpp
// This program reads a random-access file sequentially, updates
// data previously written to the file, creates data to be placed
// in the file, and deletes data previously stored in the file.
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cstdlib>       // exit function prototype
#include "BankAccount.h" // baseAccount class definition
#include <string>
#include <typeinfo>

using namespace std;
void printSavingAccounts(vector<baseAccount *> &);
void printCheckingAccounts(vector<baseAccount *> &);
void calculateInterest(vector<baseAccount *> &);
void readFile(ifstream &, vector<baseAccount *> &);

int main()
{
     // open file for reading and writing
     ifstream inCredit("inputFilePA.dat", ios::in);
     vector<baseAccount *> acctArray;
     string lastName;

     if (!inCredit)
     {
          cerr << "File could not be opened." << endl;
          exit(1);
     } // end if
     readFile(inCredit, acctArray);
     inCredit.close();
     cout << "\n*** Saving Accounts ***" << endl;
     cout << left << setw(10) << "Acct #" << setw(16) << "Last Name" << setw(11) << "First Name" << setw(18) << "City Name"
          << right << setw(10) << "Balance" << setw(15) << "Floating Rate" << endl
          << endl;
     printSavingAccounts(acctArray);
     cout << "\n*** Checking Accounts ***" << endl;
     cout << left << setw(10) << "Acct #" << setw(16) << "Last Name" << setw(11) << "First Name" << setw(18) << "City Name"
          << right << setw(10) << "Balance" << endl
          << endl;
     printCheckingAccounts(acctArray);
     calculateInterest(acctArray);
     cout << "\n*** Saving Accounts After Calculating Interest ***" << endl;
     cout << "    Base interest rate: " << setw(10) << setprecision(3) << baseAccount::baseIntrsRate << endl;
     cout << left << setw(10) << "Acct #" << setw(16) << "Last Name" << setw(11) << "First Name" << setw(18) << "City Name"
          << right << setw(10) << "Balance" << setw(15) << "Floating Rate" << endl
          << endl;
     printSavingAccounts(acctArray);
     cout << "\n*** Checking Accounts After Calculating Interest ***" << endl;
     cout << left << setw(10) << "Acct #" << setw(16) << "Last Name" << setw(11) << "First Name" << setw(18) << "City Name"
          << right << setw(10) << "Balance" << endl
          << endl;
     printCheckingAccounts(acctArray);

     return 0;
} // end main
void printSavingAccounts(vector<baseAccount *> &accounts)
{
     for (int i = 0; i < accounts.size(); i++)
     {
          savingAccount *sAcnt = dynamic_cast<savingAccount *>(accounts[i]);
          if (sAcnt != 0)
          {
               sAcnt->printAccount();
          }
     }
}
void printCheckingAccounts(vector<baseAccount *> &accounts)
{
     for (int i = 0; i < accounts.size(); i++)
     {
          checkingAccount *cAcnt = dynamic_cast<checkingAccount *>(accounts[i]);
          if (cAcnt != 0)
          {
               cAcnt->printAccount();
          }
     }
}
void calculateInterest(vector<baseAccount *> &accounts)
{
     for (int i = 0; i < accounts.size(); i++)
     {
          checkingAccount *cAcnt = dynamic_cast<checkingAccount *>(accounts[i]);
          if (cAcnt != 0)
          {
               cAcnt->calculateIntrs();
          }
          else
          {
               savingAccount *sAcnt = dynamic_cast<savingAccount *>(accounts[i]);
               if (sAcnt != 0)
               {
                    sAcnt->calculateIntrs();
               }
          }
     }
}

void readFile(ifstream &infile, vector<baseAccount *> &accounts)
{
     //accounts.resize(40);
     int accountNumber;
     string lastName;
     string firstName;
     string cityName;
     int balance;
     char accountType;
     double floatingIntrsRate;
     //int counter = 0;
     while (infile >> accountNumber >> lastName >> firstName >> cityName >> balance >> accountType)
     {
          //cout << accountNumber << " " << lastName << " " << firstName << " " << cityName << " " << balance << " " << accountType;
          if (accountType == 'S')
          {
               infile >> floatingIntrsRate;
               savingAccount *sAcnt = new savingAccount(accountNumber, lastName, firstName, cityName, balance, floatingIntrsRate);
               accounts.push_back(sAcnt);
               //accounts[counter] = &sAcnt;
               //cout << " " << floatingIntrsRate << endl;
          }
          else
          {
               checkingAccount *cAcnt = new checkingAccount(accountNumber, lastName, firstName, cityName, balance);
               accounts.push_back(cAcnt);
               //accounts[counter] = &cAcnt;
               //cout << endl;
          }
          //counter++;
     }
}