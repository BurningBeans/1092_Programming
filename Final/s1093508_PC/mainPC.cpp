// Fig. 17.7: Fig17_7.cpp
// This program reads a random-access file sequentially, updates
// data previously written to the file, creates data to be placed
// in the file, and deletes data previously stored in the file.
#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>
#include <cstdlib>       // exit function prototype
#include "BankAccount.h" // ClientData class definition

using namespace std;
void outputLine(ostream &, const ClientData &);
void printAllRecords(multimap<string, ClientData>);
void readFromRandomFile(ifstream &, multimap<string, ClientData> &);
void sameLastName(multimap<string, ClientData> mLSN, const string givenLS);

int main()
{
   // open file for reading and writing
   ifstream inCredit("inputFilePC.dat", ios::in);
   multimap<string, ClientData> mLastName;
   string lastName;

   if (!inCredit)
   {
      cerr << "File could not be opened." << endl;
      exit(1);
   } // end if
   readFromRandomFile(inCredit, mLastName);
   inCredit.clear();
   printAllRecords(mLastName);
   inCredit.close();
   cout << "Enter the last name of a customer (QUIT for quit): " << endl;
   cin >> lastName;
   while (lastName != "QUIT")
   {
      sameLastName(mLastName, lastName);
      cout << "Enter the last name of a customer (QUIT for quit): " << endl;
      cin >> lastName;
   }
} // end main
