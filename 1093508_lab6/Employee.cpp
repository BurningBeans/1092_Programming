#include <iostream>
#include "Employee.h"
using namespace std;
int Employee::count = 0;
int Employee::countAdm  = 0;
Employee::Employee(const string &firstN, const string &lastN, bool rank)
{
    firstName = firstN;
    lastName = lastN;
    eRank = rank;
    count++;
    if(eRank)
    {
        countAdm++;
    }
    cout << "Employee constructor for " << firstName << ' ' << lastName << " called. \n";

}
Employee::~Employee()
{
    cout << "~Employee() called for " << firstName << ' ' << lastName << '\n';
    count--;
    if(eRank)
    {
        countAdm--;
    }
}
string Employee::getfirstName() const
{
    return firstName;
}
string Employee::getlastName() const
{
    return lastName;
}
int Employee::getCount()
{
    return count;
}
int Employee::getAdmCount()
{
    return countAdm;
}
Employee &Employee::printfirstName()
{
    cout << firstName << ' ';
    return *this;
}
Employee *Employee::printlastName()
{
    cout << lastName << ' ';
    return this;
}
void Employee::printCount()
{
    cout << "Number of employees: " << count << '\t' << "Number of managers: " << countAdm << '\n';
}




//----------------------------------------------------------------
/*
void print(const Employee &e)
{
    cout << e.firstName << ' ' << e.lastName << ' ' << e.eRank <<'\n';
}
*/
void print(const Employee e)
{
    cout << e.firstName << ' ' << e.lastName << ' ' << e.eRank <<'\n';
}

//----------------------------------------------------------------