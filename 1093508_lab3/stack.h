#include <iostream>
#include <string>
using namespace std;
class Stack{
    private:
    int stackSize;
    int stackPtr;
    string charStack;
    //char *charStack; //don't know how to use c style string :(
    public:
    Stack(int, int, string);
    void push(char);
    char pop();
    void reset();
    bool empty();
    bool full();
    //void print(); // debug function
};
Stack::Stack(int size = 1, int ptr = 0,string c_stack = "")
{
    stackSize = size;
    stackPtr = ptr;
    charStack = c_stack;
}
void Stack::push(char c)
{
    charStack += c;
    stackSize++;
}
char Stack::pop()
{
    return *charStack.rbegin();
}
/*
void Stack::print()
{
    cout << charStack;
    cout << endl;
}
*/