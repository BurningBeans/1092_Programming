#include <iostream>
#include "SmartPtr.h"
using namespace std;
class Dessert
{
public:
 ~Dessert() { cout << "Dessert destructor\n"; }
 void eat() { cout << "Eating dessert\n"; };
};
class Pen
{
public:
 ~Pen() { cout << "Pen destructor\n"; }
 void write() { cout << "Writing using a pen\n"; }
};
int main()
{
 MySmartPointer< Dessert > myMealPtr( new Dessert );
 MySmartPointer< Pen > myPenPtr( new Pen );
 char choice;
 while ( cin >> choice )
 {
 switch ( choice )
 {
 case '1':
 myMealPtr->eat();
 break;
 case '2':
 ( *myPenPtr ).write();
 break;
 default:
 return 0;
 }
 }
}