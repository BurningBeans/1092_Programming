#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Stack{
    private:
    int stackSize;
    int stackPtr;
    char *c_array;
    public:
    Stack(int = 1, int = 0, char * = NULL);
    void push(char);
    char pop();
    void reset();
    bool empty();
    bool full();
    //void print(); // debug function
};
Stack::Stack(int size, int ptr,char *c_arr)
{
    stackSize = size;
    stackPtr = ptr;
    c_array = new char [stackSize];
}
void Stack::push(char c)
{
    c_array[stackPtr] = c;
    stackPtr++;
}
char Stack::pop()
{
    stackPtr--;
    return c_array[stackPtr+1];
}
void Stack::reset()
{
    stackPtr = 0;
    //cout <<"The stack is reset.\n";
}
bool Stack::empty()
{
    if(stackPtr == 0)
        return true;
    return false;
}
bool Stack::full()
{
    if(stackPtr == stackSize)
        return true;
    return false;
}
/*
void Stack::print()
{
    cout << c_array;
    cout << endl;
}
*/
void checkExpression(string, Stack &);
int main()
{
    ifstream inFile("inputs",ios::in);
    
    int stacksize = 0;
    inFile >> stacksize;
    int inputs = 0;
    inFile >>inputs;
    Stack aStack(stacksize,0,NULL);
    string str = "";
    for(int i = 0; i < inputs; i++)
    {
        inFile >> str;
        checkExpression(str,aStack);
    }
    inFile.close();
}
void checkExpression(string str, Stack &aStack)
{
    for(char i: str)
    {
        if(i == '(')
        {
            if(aStack.full())
            {
                cout << "Stack is full" << endl;
                aStack.reset();
                return;
            }
            else
                aStack.push(i);
        }
        if(i == ')')
        {
            if(aStack.empty())
            {
                cout << "more )'s\n";
                aStack.reset();
                return;
            }
            else
            {
                aStack.pop();
            }
        }
    }
    if(!aStack.empty())
    {
        cout << "more ('s\n";
    }
    else
    {
        cout <<"correct\n";
    }
    aStack.reset();
}