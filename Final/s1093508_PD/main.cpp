// Fig. 11.8: fig11_08.cpp
// Array class test program.
#include <iostream>
#include "Array.cpp"
#include <string>
using namespace std;

int main()
{
   Array<int> integers1(4, 4); // seven-element Array
   Array<int> integers2;       // 10-element Array by default

   cout << "Enter 4 * 4 and 3*3 integers:" << endl;
   cin >> integers1 >> integers2;

   cout << "\nAfter input, the Arrays contain:\n"
        << "integers1: \n"
        << integers1
        << "integers2: \n"
        << integers2;

   // use overloaded inequality (!=) operator
   cout << "\nEvaluating: integers1 != integers2" << endl;

   if (integers1 != integers2)
      cout << "integers1 and integers2 are not equal" << endl;

   // create Array integers3 using integers1 as an
   // initializer; print size and contents
   Array<double> double1(2, 5); // invokes copy constructor
   cout << "\nEnter 2*5 double precision numbers:" << endl;
   cin >> double1;

   // use overloaded assignment (=) operator
   cout << "\nCreate double2 initialized with double1: " << endl;
   Array<double> double2(double1); // note target Array is smaller

   cout << "double1: \n"
        << double1
        << "double2: \n"
        << double2;

   // use overloaded equality (==) operator
   cout << "\nEvaluating: double1 == double2" << endl;

   if (double1 == double2)
      cout << "double1 and double2 are equal" << endl;
   // use overloaded subscript operator to create lvalue
   cout << "\nAssigning 10.01 to double1(1, 4)" << endl;
   double1(1, 4) = 10.01;
   cout << "double1:\n"
        << double1 << endl;

   Array<string> strA(5, 2);
   cout << "Enter 5 * 2 strings:" << endl;
   cin >> strA;
   strA(1, 1) = "abcd";
   cout << "After assignment of strS(1, 1) = \"abcd\":\n"
        << strA;
   try
   {
      strA(3, 3) = "xyzu";
   }
   catch (char const *outRangeMesg)
   {
      cout << outRangeMesg << endl;
   }
   cout << "After assignment of strS(3, 3) = \"xyzu\":\n"
        << strA;
   try
   {
      strA(-1, 1) = "xyzu";
   }
   catch (char const *outRangeMesg)
   {
      cout << outRangeMesg << endl;
   }
   cout << "After assignment of strS(-1, 1) = \"xyzu\":\n"
        << strA;

   Array<double> largeD(100000, 100000);
   return 0;
} // end main
