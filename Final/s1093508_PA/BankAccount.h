// Fig. 17.10: ClientData.h
// Class ClientData definition used in Fig. 17.12-Fig. 17.15.
#ifndef CLIENTDATA_H
#define CLIENTDATA_H

#include <string>
using namespace std;

class baseAccount
{
public:
    static const double baseIntrsRate; // base interest rate
   // default ClientData constructor
   baseAccount( int = 0, string = "", string = "", string = "", int = 0);

   // accessor functions for accountNumber
   void setAccountNumber( int );
   int getAccountNumber() const;

   // accessor functions for lastName
   void setLastName( string );
   string getLastName() const;

   // accessor functions for firstName
   void setFirstName( string );
   string getFirstName() const;

   void setCityName(string);
   string getCityName() const;
   // accessor functions for balance
   void setBalance( int );
   int getBalance() const;
   static void incNumOfAccount();
   static int getNumOfAccount();
   virtual void printAccount() const;
   virtual int calculateIntrs() = 0;

private:
   int accountNumber;
   string lastName;
   string firstName;
   string cityName;
   int balance;
   static int numOfAccount;
}; // end class ClientData

class savingAccount : public baseAccount
{
public:
    savingAccount( int = 0, string = "", string = "", string = "", int = 0, double = 0.0);
    void setFloatingIntrsRate(double);
    double getFloatingIntrsRate() const;
    virtual void printAccount() const;
    virtual int calculateIntrs();
    static void incNumOfAccount();
    static int getNumOfAccount();
private:
    double floatingIntrsRate;
    static int numOfAccount;
};

class checkingAccount: public baseAccount
{
public:
    checkingAccount( int = 0, string = "", string = "", string = "", int = 0.0);
    virtual void printAccount() const;
    virtual int calculateIntrs();
    static void incNumOfAccount();
    static int getNumOfAccount();
private:
    static int numOfAccount;
};

#endif
