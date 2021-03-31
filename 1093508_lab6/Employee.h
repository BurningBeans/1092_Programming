#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;
class Employee{

public:
    Employee(const string &, const string &, bool);
    ~Employee();
    string getfirstName() const;
    string getlastName() const;
    static int getCount();
    static int getAdmCount();
    Employee &printfirstName();
    Employee *printlastName();

    static void printCount(); // using static for all to access the print count

private:
    string firstName;
    string lastName;
    static int count;// person count
    static int countAdm;// manager count
    bool eRank; //true if manager

    //friend void print(const Employee&);
    friend void print(const Employee);
};
#endif