#include <iostream>
#include "queue.cpp"
using namespace std;
int main()
{
    int size = 0;
    cin >> size;
    Queue ideal = Queue(size);
    Queue arriving = Queue(size);
    int test_case = 0;
    cin >> test_case;
    int counter = 1;
    while(test_case--)
    {
        cout << "Test #" << counter << " .\n";
        int time = 0;
        int element = 0;
        cin >> element;
        int num = 0;
        for(int i = 0; i < element; i++)
        {
            cin >> num;
            ideal.enqueue(num);
        }
        for(int i = 0; i < element; i++)
        {
            cin >> num;
            arriving.enqueue(num);
        }
        while(!arriving.isEmpty())
        {
            if(arriving.peek() != ideal.peek())
            {
                arriving.enqueue(arriving.dequeue());
                arriving.printQueue();
                time++;
            }
            if(arriving.peek() == ideal.peek())
            {
                arriving.dequeue();
                ideal.dequeue();
                time+=2;
            }
        }
        cout << time << endl;




        ideal.clearQueue();
        arriving.clearQueue();
        counter++;
    }
}