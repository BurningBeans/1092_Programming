#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
void addedges(vector <int>*, int, int);
void traversal(vector <int>*, int);
void DFS(vector <int>*, bool*, int);
int main()
{
    int t = 0;//test cases
    cin >> t;
    while (t--)
    {
        int vertices, edges;
        cin >> vertices >> edges;
        vector <int> varr[vertices];//create vectors of vertices and each vector store the adjacency list of the vertice
        for(int i = 0; i < edges; i++)//add edge here
        {
            int u, v;
            cin >> u >> v;
            addedges(varr, u, v);
        }
        traversal(varr,vertices);
    }
}
void addedges(vector <int> *int_vector,int u ,int v)//create an adjacency list
{
    int_vector[u].push_back(v);
    int_vector[v].push_back(u);
}
void traversal(vector <int> *int_vector,int vertices)
{
    bool *traversed = new bool [vertices];//create an array of each vertices to check traversed or not
    for(int i = 0; i < vertices; i++)
        traversed[i] = false;
    for(int i = 0; i < vertices; i++)
    {
        if(!traversed[i])
            DFS(int_vector,traversed,i);
    }


    bool check = true;
    for(int i = 0; i < vertices; i++)
    {
        if(!traversed[i])
            check = false;
    }
    if (check)
        cout << "Disconnected\n";
    else
        cout << "Connected\n";
    delete traversed;
}
void DFS(vector <int> *int_vector, bool *traversed, int vertex)
{
    for(int i = 0; i < int_vector[vertex].size(); i++)
    {
        if(int_vector[vertex][i])//if vertex exist in adj list
        {
            traversed[vertex] = true;//traversed = ture
            if(!traversed[int_vector[vertex][i]])//if vertex is not traversed
                DFS(int_vector, traversed,i);
        }
    }
}