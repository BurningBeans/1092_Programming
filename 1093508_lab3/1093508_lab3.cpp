#include <iostream>
#include <string>
#include <vector>
#include "stack.h"
using namespace std;
void checkExpression(string, Stack &);
int main()
{
    int stacksize = 0;//
    cin >> stacksize;
    int inputs = 0;
    cin >> inputs;
    Stack aStack(stacksize,0,NULL);
    string str = "";
    for(int i = 0; i < inputs; i++)
    {
        cin >> str;
        checkExpression(str,aStack);
    }
}
void checkExpression(string str, Stack &aStack)
{
    for(char i: str)
    {
        if(aStack.full())
        {
            cout << "Stack is full" << endl;
            return;
        }
        if(i == '(')
            aStack.push(i);
        else if(i == ')')
            aStack.push(i);
    }
    //
    int counters = 0;//if counter < 0 meaning "(" is more than ")"
    while(!aStack.empty())
    {
        if(0 > counters)
        {
            break;
        }
        if(aStack.pop()==')')
        {
            aStack.ptrminus();
            counters++;
        }
        else if(aStack.pop()=='(')
        {
            aStack.ptrminus();
            counters--;
        }
    }
    //
    if(counters > 0)
    {
        cout << "more )'s \n";
    }
    else if(counters < 0)
    {
        cout << "more ('s \n";
    }
    else
    {
        cout << "correct \n";
    }
    aStack.reset();
}