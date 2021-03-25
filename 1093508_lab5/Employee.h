#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include "Date.h" // include Date class definition
using namespace std;
class Employee
{
public:
    Employee( const string &, const string &, const Date &, const Date &,const Date &, int );
    void print() const;
    Employee &eDismiss(const Date &);
    Employee &increaseSalary(int);
    ~Employee(); // provided to confirm destruction order
private:
    string firstName; // composition: member object
    string lastName; // composition: member object
    const Date birthDate; // composition: member object
    const Date hireDate; // composition: member object
    Date dismissDate; // composition: member object
    int monSalary;
}; // end class Employee
#endif