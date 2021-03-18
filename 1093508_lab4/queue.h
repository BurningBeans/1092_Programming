#ifndef _QUEUE_h_
#define _QUEUE_h_
class Queue
{
    private:
    int size; // the size of a queue
    int *intQueue; // the pointer to a dynamically created array
    int front; // index to the front most element in a queue
    int rear; // index to the rear most element in a queue
    int count; // the number of elements in the queue;
    public:
    Queue(int = 10); // constructor with queue size initialized to 10
    ~Queue(); // destructor
    void enqueue(int); // Insert an element in the rear end of a queue
    int dequeue(); // remove and then return the front most element in the queue
    int peek(); // return the front most element in the queue
    int getCount(); // return the number of elements stored in the queue
    int getSize(); // return queue size 
    bool isEmpty(); // return true if queue is empty
    bool isFull(); // return true if queue is full
    void clearQueue(); // clear the content of queue and reset front, rear, and count
    void printQueue(); // print the content of a queue from front to rear.
};
#endif