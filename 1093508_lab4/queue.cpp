#include <iostream>
#include "queue.h"
using namespace std;
Queue::Queue(int insize)
{
    cout << "A Queue of size " << insize << " is created." << endl;
    size = insize;
    intQueue = new int [size];
    front = 0;
    rear = -1;
    count = 0;
}
Queue::~Queue()
{
    cout <<"A Queue of size " << size << " is destruct." <<endl;
}
void Queue::enqueue(int num)
{
    intQueue[rear+1] = num;
    rear++;
    count++;
}
int Queue::dequeue()
{
    int returning = intQueue[front];
    for(int i = 0; i < count-1; i++)
    {
        intQueue[i] = intQueue[i+1];
    }
    rear--;
    count--;
    return returning;
}
int Queue::peek()
{
    return intQueue[front];
}
int Queue::getCount()
{
    return count;
}
int Queue::getSize()
{
    return size;
}
bool Queue::isEmpty()
{
    if(count == 0)
        return true;
    return false;
}
bool Queue::isFull()
{
    if(count == size)
        return true;
    return false;
}
void Queue::clearQueue()
{
    delete []intQueue;
    intQueue = new int [size];
    front = 0;
    rear = -1;
    count = 0;
}
void Queue::printQueue()
{
    for(int i = 0 ; i < count ; i++)
    {
        cout << intQueue[i] << " ";
    }
    cout << '\n';
}