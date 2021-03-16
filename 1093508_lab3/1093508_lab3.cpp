#include <iostream>
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
    c_array = c_arr;
}
void Stack::push(char c)
{
    c_array[stackPtr] = c;
    stackPtr++;
}
char Stack::pop()
{
    char c = c_array[stackPtr];
    c_array[stackPtr] = NULL;
    stackPtr--;
    return c;
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
    int stacksize = 0;
    cin >> stacksize;
    int inputs = 0;
    cin >> inputs;
    Stack aStack(stacksize, 0, new char[stacksize]);
    string str = "";
    for(int i = 0; i < inputs; i++)
    {
        cin >> str;
        cout << "\n";
        checkExpression(str,aStack);
        cout << '\n';
    }
}
void checkExpression(string str, Stack &aStack)
{
    if(str.empty())//Not used in the example output
    {
        cout << "Empty input!";
        return;
    }
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