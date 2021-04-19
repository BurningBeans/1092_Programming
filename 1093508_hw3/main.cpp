#include <iostream>
#include "Complex.cpp"
using namespace std;
int main()
{
    Complex c1( 3.0, 2.0 );
    Complex c2 = c1;
    Complex c3( 5.1 );
    const Complex c4( 2.0, 1.0 );
    c1.add( c3 ).print();
    cout << ", ";
    c2.multiply( c4 ).print();
    cout << ", ";
    c2.print();
    cout << ", ";
    c1.add( c4 ).add( c4 ).print();
    cout << ", ";
    c4.print();
    cout << "\n";
}