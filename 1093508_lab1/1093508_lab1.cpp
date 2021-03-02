#include <iostream>
#include <set>
#include <iomanip>
#include <fstream>
using namespace std;
struct NODE
{
    int data;
    NODE *link;
};
void createList(ifstream &, NODE **);
void deleteElements(ifstream &, NODE **);
bool searchLinkedList(NODE *, int, NODE **, NODE **);
void insertLinkedList(NODE **, int );
void deleteLinkedList(NODE **, int );
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
    createList(inFile, &listHead);
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
    deleteElements (inFileDel, &listHead);
    displayList (listHead);
    inFileDel.close();
    return 0;
}
void createList(ifstream &inFile, NODE **head)
{
    set <int,greater<int>> numbers_set;
    int num = 0;
    while(inFile >> num)
    {
        numbers_set.insert(num);
    }
    NODE *first, *cur, *prev;
    for(auto i: numbers_set)//range base for loop
    {
        cur = (NODE *)malloc(sizeof(NODE));
        cur-> data = i;
        if(i == *numbers_set.begin()) // if i value is the first in the set, first is set to current.
            first = cur;
        else
            prev -> link = cur;
        cur -> link=NULL;
        prev = cur;
    }
}
void deleteElements(ifstream &inFileDel, NODE **head);
bool searchLinkedList(NODE *head, int, NODE **prePtr, NODE **curPtr);
void insertLinkedList(NODE **head, int data);
void deleteLinkedList(NODE **head, int data);
void displayList(NODE *head);