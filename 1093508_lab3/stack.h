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
    //c_array = c_arr;
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
    if(stackPtr-1 == stackSize)
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