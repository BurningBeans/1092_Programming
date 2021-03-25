#include <iostream>
#include "Employee.h"
#include "Date.h"
using namespace std;
Employee::Employee(const string &first, const string &last, const Date &dateOfBirth, const Date &dateOfHire, const Date &dateOfDismiss, int mSalary)
    :firstName(first),
    lastName(last),
    birthDate(dateOfBirth),//member function needed to initialized here
    hireDate(dateOfHire),
    monSalary(mSalary),//this can be initialized inside the bracket below
    dismissDate(dateOfDismiss)
{
    cout << "Employee object constructor: " << firstName << ' ' << lastName <<" Monthly pay: " << monSalary <<" \n";
    if(!hireDate.compareDate(birthDate)||!dismissDate.compareDate(hireDate))//check date is valid
    {
        cout << firstName << ' ' << lastName << " with inconsistent dates! \n";
    }
}
void Employee::print() const
{
    cout << firstName << ' ' << lastName << " Hired:";
    hireDate.print();
    cout << " Birthday: ";
    birthDate.print();  
    cout << " Monthly paid: " << monSalary;
    cout << " Dimissing: ";
    dismissDate.print();
    cout << '\n';
}
Employee::~Employee()
{
    cout << "Employee object destructor: " << lastName << ", " << firstName << '\n';
}
Employee &Employee::eDismiss(const Date &dateOfDismiss)
{
    //validate dateOfDismiss first, then set the dismissDate
    //if(!dismissDate.compareDate(dateOfDismiss))//don't know why this is wrong
    if(!dateOfDismiss.compareDate(dismissDate))
    {
        cout << firstName << ' ' << lastName << " with inconsistent dates! \n";
    }
    //else
    dismissDate = dateOfDismiss;
    return *this;
}
Employee &Employee::increaseSalary(int salary)
{
    monSalary += salary;
    return *this;
}