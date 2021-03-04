#include <iostream>
#include <set>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;
struct NODE
{
    int data;
    NODE *link;
};
void createList(ifstream &, NODE *&);
void deleteElements(ifstream &, NODE *&);
bool searchLinkedList(NODE *&, int, NODE *&, NODE *&);
void insertLinkedList(NODE *&, int );
void deleteLinkedList(NODE *&, int );
void displayList(NODE *);
int main()
{
    string dataFilename;
    ifstream inFile;
    string delDataFilename;
    ifstream inFileDel;
    // First part
    cout << "File name for creating linked list: ";
    cin >> dataFilename;
    cout << endl;
    inFile.open(dataFilename);
    NODE *listHead=NULL;
    if (!inFile){
        cout << "File open error!" << endl;
        exit(1);
    }
    createList(inFile, listHead);
    inFile.close();
    displayList(listHead);
    // Second part
    cout << "\nFile name for linked list deletion: ";
    cin >> delDataFilename;
    inFileDel.open(delDataFilename);
    if (!inFileDel){
        cout << "File open error!" << endl;
        exit(1);
    }
    cout << "\nList after deletion:" << endl;
    deleteElements (inFileDel, listHead);
    displayList (listHead);
    inFileDel.close();
    return 0;
}
//----------------------------------------------------------------
void createList(ifstream &inFile, NODE *&head)
{
    set <int,greater<int>> numbers_set; // using set to store numbers
    int num = 0;
    while(inFile >> num)
    {
        numbers_set.insert(num);
    }
    for(auto i: numbers_set)// range base for loop for each numbers in the set
    {
        insertLinkedList(head,i);
        /*
        cur = new NODE; // create a node for each numbers in the set
        cur -> data = i; // allocate data in the node
        if(i == *numbers_set.begin()) // if i value is the first in the set, first is set to current.
            head = cur;
        else
            prev -> link = cur; // else previous node's link to current node
        cur -> link = NULL; // current link point to NULL
        prev = cur; // move to next node and set previous node to current
        */
    }
}
void deleteElements(ifstream &inFileDel, NODE *&head)
{
    int num = 0;
    vector <int> numbers;
    while(inFileDel >> num)
    {
        numbers.push_back(num);
    }
    for(auto i:numbers)
    {
        deleteLinkedList(head,i);
    }
    
}
bool searchLinkedList(NODE *&head, int key, NODE *&prePtr, NODE *&curPtr)//return true if data is found in the list
{
    curPtr = head;
    prePtr = NULL;
    while(curPtr!=NULL)
    {
        if(curPtr -> data == key)
        {
            return true;
        }
        prePtr = curPtr;
        curPtr = curPtr -> link;
    }
    return false;
}
void insertLinkedList(NODE *&head, int key)
{
    NODE *cur, *prev;
    cur = new NODE; // create a node for each numbers in the set
    cur -> data = key; // assign data in the node
    if(head == NULL)
        head = cur;
    else
        prev -> link = cur; // else previous node's link to current node
    cur -> link = NULL; // current link point to NULL
    prev = cur; // move to next node and set previous node to current
    return;
}
void deleteLinkedList(NODE *&listHead, int key)
{
    NODE *curPtr;
    NODE *prePtr;
    if(!searchLinkedList(listHead, key, prePtr, curPtr)) // not found
        return;
    if(prePtr == NULL)
        listHead = curPtr->link;
    else
        prePtr->link = curPtr->link;
    curPtr->link = NULL;
    delete curPtr;
}
/*
void deleteLinkedList(NODE *&listHead, int key)
{
    NODE *curPtr = listHead;
    NODE *prePtr = NULL;
    //if(!searchLinkedList(listHead, key, curPtr, prePtr)) // not found
    //    return;
    while(curPtr != NULL)
    {
        if(curPtr -> data == key)
        {
            if(prePtr == NULL)
                listHead = curPtr -> link;
            else
                prePtr -> link = curPtr -> link;
            //curPtr -> link = NULL;
            delete curPtr;
        }
        prePtr = curPtr;
        curPtr = curPtr -> link;
    }
    return;
}
*/
void displayList(NODE *head)
{
    int count=0; // Used for counting the number of nodes
    NODE *tempPtr = head; // Set tempPtr to the head of the linked-list
    while(tempPtr != NULL) // Check whether get to the end of the linked-list
    {
        cout << tempPtr -> data << " "; // Print out the data stored in the node
        tempPtr = tempPtr -> link; // Move to the next node
        count++;
        if(count%15 == 0) // Change line if already printing 15 numbers
            cout << endl;
    }
    cout << endl;
    cout << "Total number of elements in the linked list: " << count << endl;
}