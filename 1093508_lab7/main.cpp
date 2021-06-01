#include "Array.cpp"
int main()
{
    Array intergers1(7);//A size of 5 elements Array
    Array intergers2;//Default Array size of 10

    //print intergers1 size and contents
    cout << "Array size of intergers1 is " << intergers1.getSize() << "\nArray after initialization:\n" << intergers1;

    //print intergers2 size and contents
    cout << "Array size of intergers2 is " << intergers2.getSize() << "\nArray after initialization:\n" << intergers2;

    //input and print intergers 1 and 2
    cout << "\n Enter 17 intergers:\n";
    cin >> intergers1 >> intergers2;
    cout << "\n After input, the Array contain:\n" << "intergers1:\n" << intergers1 << "intergers2:\n" << intergers2;

    //use overloaded != operator
    cout << "\nEvaluating : intergers1 != intergers2\n";
    if (intergers1 != intergers2)
        cout << "intergers1 and intergers2 are not equal\n";
    
    //create intergers3 using intergers1 as an initializer, print size and contents
    Array intergers3(intergers1);
    cout << "Array size of intergers3 is " << intergers3.getSize() << "\nArray after initialization:\n" << intergers3;

    //use overloaded = operator
    cout << "\nAssigning intergers2 to intergers1:\n";
    intergers1 = intergers2;
    cout << "intergers1:\n" << intergers1 << "intergers2:\n" << intergers2;
    
    //use overloaded == operator
    cout <<"Evaluating: intergers1 == intergers2" << endl;
    if(intergers1 == intergers2)
        cout << "intergers1 and intergers2 are equal\n";
    
    //use overloaded subscript operator to create rvalue
    cout << "\n\nAssigning 1000 to intergers1[5]" << endl;
    intergers1[5] = 1000;
    cout << "intergers1\n" << intergers1;
    //------------------------------------------------ inserted lines
    
    intergers3 = -intergers3;
    cout << "intergers2 \n" << intergers2 << endl;
    cout << "intergers3 \n" << intergers3 << endl;
    Array C;
    C = intergers1 + intergers2 + intergers3;
    cout << "Array C = intergers1 + interger2 + intergers3 \n" << C;
    int k = 30;
    C >> k;
    cout << "Shifting the elements of C to the right by " << k << " places\n" << C;
    //------------------------------------------------

    //attempt to use out-of-range subscript
    cout << "\n Attempting to assign 1000 to intergers1[15]" << endl;
    intergers1[15] = 1000;
}