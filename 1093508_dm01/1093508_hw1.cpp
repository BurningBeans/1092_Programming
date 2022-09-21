#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
ofstream outFile("output.txt");//file output
void addedges(vector <int>*, int, int);
void check(vector <int>*,int);
int main()
{
    ifstream inFile("input.txt");//file input
    int t = 0;//test cases
    inFile >> t;
    while (t--)
    {
        int vertices, edges;
        inFile >> vertices >> edges;
        vector <int> varr[vertices];//create vectors of vertices and each vector store the adjacency list of the vertice
        for(int i = 0; i < edges; i++)//add edge here
        {
            int u, v;
            inFile >> u >> v;
            addedges(varr, u, v);
        }
        check(varr,vertices);
    }
    inFile.close();
    outFile.close();
}
void addedges(vector <int> *int_vector,int u ,int v)//create an adjacency list
{
    int_vector[u].push_back(v);
    int_vector[v].push_back(u);
}
void check(vector <int>* varr, int vertices)
{
    for(int i = 0; i < vertices; i++)//for each vertex in the list check if connected vertices == 0
    {
        if(varr[i].size() == 0)
        {
            outFile << "disconnected\n";
            return;
        }
    }
    outFile << "connected\n";
}

