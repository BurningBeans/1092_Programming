#include <iostream>
#include <string>
#include <vector>
#include "stack.h"
using namespace std;
int main()
{
    Stack aStack;
    char c;
    while(cin>>c)
    {
        aStack.push(c);
        cout << "Last char in stack is: " << aStack.pop() <<'\n';
    }
}