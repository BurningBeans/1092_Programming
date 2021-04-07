#include <iostream>
#include "Employee.h"
using namespace std;
int Employee::count = 0;
int Employee::fcount = 0;
int Employee::mcount = 0;
Employee::Employee(const string &firstN, const string &lastN, char gen)
:firstName(firstN),
lastName(lastN),
gender(gen)
{
    count++;
    if(gender == 'M')
    {
        mcount ++;
    }
    else if(gender == 'F')
    {
        fcount++;
    }
    else
    {
        cout << "Employee's gender specification is incorrect. " << gender << endl;
    }
    cout << "Employee constructor for " << firstName << ' ' << lastName << " called. \n";

}
Employee::~Employee()
{
    cout << "~Employee() called for " << firstName << ' ' << lastName << '\n';
    count--;
    if(gender == 'M')
    {
        mcount--;
    }
    if(gender == 'F')
    {
        fcount--;
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
int Employee::getfCount()
{
    return fcount;
}
int Employee::getmCount()
{
    return mcount;
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
    cout << "Number of employees: " << count << '\t' << "Number of male employees: " << mcount << '\t' << "Number of female employees: " << fcount << '\n';
}




//----------------------------------------------------------------

void print(const Employee &e)
{
    cout << e.firstName << ' ' << e.lastName << ' ' << e.gender <<'\n';
}
/*
void print(const Employee e)
{
    cout << e.firstName << ' ' << e.lastName << ' ' << e.gender <<'\n';
}
Employee::Employee(const Employee &e)//copy constructor
{
    firstName = e.firstName;
    lastName = e.lastName;
    gender = e.gender;
    count++;
    if(gender == 'M')
    {
        mcount ++;
    }
    if(gender == 'F')
    {
        fcount++;
    }
}
*/
//----------------------------------------------------------------