#include <iostream>
#include "Hugeint.h"
using namespace std;
int main()
{
    Hugeint n1(7654321);
    Hugeint n3("99999999999999999999999999999");
    Hugeint n4("1");
    Hugeint n5(n4);

    cout << "n1 is " << n1 << "\nn3 is " << n3 << "\nn4 is " << n4 << "\nn5 is " << n5 << "\n\n";
    Hugeint n6 = n3 + n4;
    cout << "n6 = " << n3 << " + " << n4 << " = " << n6 << "\n\n";
    cout << "9 + n1 = " << 9 + n1 << " " << "9" + n1 << " " << n1 + 9 << endl;
    cout << "n4+100+900+n5= " << n4 + 100 + "900" + n5  << endl;

    cout << "n3++ = " << n3++ << endl;
    cout << "n3 = " << n3 << endl;
    cout << "++n3 = " << ++n3 << endl;
    cout << "n3 = " << n3 << endl;
    
    if(n3 >= n1)
        cout << "\nyes-1";
    else
        cout << "\nno-1";
    if(n3 >= 100)
        cout << "\nyes-2";
    else
        cout << "\nno-2";
    if(100 >= n3)
        cout << "\nyes-3";
    else
        cout << "\nno-3";
    if(n3 >= "100")
        cout << "\nyes-4";
    else
        cout << "\nno-4";
    if("100" >= n3)
        cout << "\nyes-5";
    else
        cout << "\nno-5";
}