#include <iostream>
#include "Date.h"
#include "Date.cpp"
#include "Employee.h"
#include "Employee.cpp"
using namespace std;
int main()
{
    Date birth( 3, 24, 1961 );
    Date hire( 4, 12, 1998 );
    Date dismiss( 2, 28, 2021);
    Date zero;
    Employee manager1( "Tom", "Crouse", birth, hire, zero, 66000 );
    cout << endl;
    manager1.print();
    manager1.increaseSalary(2000).print();
    manager1.eDismiss(dismiss)->print();
    cout << "\nTest Date constructor with invalid values:\n";
    Date lastDayOff( 14, 35, 1994 ); // invalid month and day
    cout << endl;
    Date birth1( 1, 1, 1968 );
    Date hire1( 1, 1, 1994 );
    Date dismiss1(3, 28, 1990);
    Employee E1( "Mary", "Hunton", birth1, hire1, dismiss1, 45000 );
    cout << endl;
    Date dismiss2(3,28, 2000);
    E1.eDismiss(dismiss2)->print();
    E1.increaseSalary(-2000).print();
} // end main