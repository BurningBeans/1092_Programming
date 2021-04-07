#include <iostream>
#include "Employee.cpp"
using namespace std;
int main()
{
    cout << "Number of employees before instantiation of any class object is " << Employee::getCount() << endl;
    {
        Employee e1 ("Susan", "Baker", 'M');
        Employee e2 ("Robert", "Jones", 'F');
        Employee e3 ("Emily", "Willow", 'F');
        Employee e4 ("John", "Reid", 'K');
        Employee e5 ("Maria", "Vinci", 'M');
        Employee e6 ("Vincent", "Url", 'F');
        Employee e7 ("RB", "Lin", 'M');
        print(e5);
        print(e6);

        cout <<"Number of employees after objects are instantiated is " << Employee::getCount() << endl;
        
        cout <<"\n\nEmployee 1: " << e1.getfirstName() << ' ' << e1.getlastName() << "\nEmployee 2: " << e2.getfirstName() << ' ' << e2.getlastName() << "\n\n";

        Employee e8("Tomas", "Hwang", 'F');
        Employee e9("James", "Wang", 'F');
        cout << "Number of employees after objects are instantiated is: \n";
        Employee::printCount();
        
        cout << "\n\nEmployee 3: ";
        e3.printfirstName().printlastName();
        cout << "\nEmployee 3: ";
        e3.printlastName()->printfirstName();
        
        cout << "\nEmployee 4: ";
        e4.printfirstName().printlastName();
        cout << "\nEmployee 4: ";
        e4.printlastName()->printfirstName();
        cout << endl << endl;

    }//end nested scope
    cout << "Number of employees after objects are deleted is " << "Number of employees: " << Employee::getCount() << " Female employees: " << Employee::getfCount() << " Male employees: " << Employee::getmCount() << endl;
}