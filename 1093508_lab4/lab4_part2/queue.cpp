#include <iostream>
#include "queue.h"
using namespace std;
Queue::Queue(int insize)
{
    cout << "A Queue of size " << insize << " is created." << endl;
    size = insize;
    intQueue = new int [size];
    front = -1;
    rear = -1;
    count = 0;
}
Queue::~Queue()
{
    cout <<"A Queue of size " << size << " is destruct." <<endl;
}
void Queue::enqueue(int num)
{
    if (rear+1 >= front)
    {
        intQueue[0] = num;
        rear = 0;
        count++;
    }
    else
    {
        intQueue[rear+1] = num;
        rear++;
        count++;
    }
}
int Queue::dequeue()
{
    int returning = intQueue[front+1];
    front++;
    count--;
    return returning;
}
int Queue::peek()
{
    return intQueue[front+1];
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
    front = -1;
    rear = -1;
    count = 0;
}
void Queue::printQueue()
{
    if(front > rear)
    {
        for(int i = front; i < size; i++)
        {
            cout << intQueue[i] << ' ';
        }
        for(int i = 0; i < rear; i++)
        {
            cout << intQueue[i] << ' ';
        }
    }
    else
    {
        for(int i = front+1; i < rear+1; i++)
        {
            cout << intQueue[i] << ' ';
        }
    }
    cout << '\n';
}