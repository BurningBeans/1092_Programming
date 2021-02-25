#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
struct NODE
{
    int data;
    NODE *link;
};
void createList(ifstream &inFile, NODE **head);
void deleteElements(ifstream &inFileDel, NODE **head);
bool searchLinkedList(NODE *head, int, NODE **prePtr, NODE **curPtr);
void insertLinkedList(NODE **head, int data);
void deleteLinkedList(NODE **head, int data);
void displayList(NODE *head);
int main(int argc, char **)
{
    int a = 10;
    int *b = &a;
    cout << b;    
}