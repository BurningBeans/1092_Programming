#include <iostream>
#include <stdexcept>
#include <new>
#include "Array.h"
using namespace std;
int main()
{
    Array intergers1(5);
    Array intergers2;

    cout << "Enter 15 intergers:" << endl;
    cin >> intergers1 >> intergers2;
    
    cout << "\nAfter input, the Arrays contain:\n" << "intergers1:\n" << intergers1 << "intergers2:\n" << intergers2;

    cout << "\nEvaluating: intergers1 != intergers2" << endl;
    if(intergers1 != intergers2)
        cout << "intergers1 and intergers2 are not equal." << endl;

    const Array intergers3(intergers1);
    cout << "\nAssigning: intergers2 to intergers1: "<< endl;

    intergers1 = intergers2;
    

    cout << "intergers1:\n" << intergers1 << "intergers2:\n" << intergers2;

    cout << "Execute intergers2 = intergers2:" << endl;
    //-------------------------------
    try{
            intergers2 = intergers2;
    }
    catch(exception &)
    {
        cout << "ARRAY TRIED TO ASSIGN ITSELF!!\n";
    }
    //-------------------------------
    cout << "\nintergers1[2] is " << intergers1[2] << endl;
    try{
        cout << "\nintergers3[25] is " << intergers3[25] << endl;
    }
    catch(exception&){
        cout << "Array reading is not done.\n";
    }
    cout << "\n\nAssigning 1000 to intergers1[8]:\n";
    intergers1[8] = 1000;
    cout << "interger1:\n" << intergers1 << endl;

    cout << "\nAttempt to assign 1000 to intergers1[23]\n";
    try{
        intergers1[23] = 1000;
    }
    catch(exception &){
        cout << "Array writing is not done.\n";
    }
    
    int *ptr[50];
    cout << "Memory allocation for large arrays.\n";

    try{
        for(int i=0; i < 50; i++)
        {
            //Array intergerx(50000000);
            //ptr[i] = intergerx;
            ptr[i] = new int[500000000];
            cout << "ptr[" << i << "] points to 500,000,000 new intergers.\n";
        }
    }
    catch(bad_alloc &balloc)
    {
        cout << "Memory allocation exception occurrs : " << balloc.what() << endl;
    }
}