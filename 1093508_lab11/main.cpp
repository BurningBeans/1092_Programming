#include <iostream>
#include <sstream>
#include <string>
#include <algorithm> // std::sort
#include <vector>
using namespace std;
int main()
{
    int testcase; //Number of test cases
    string aLine;
    stringstream ssLine;
    int dist[500] = {0}; // Storing distance
    int counter = 0;
    while (getline(cin, aLine))
    { // completing reading the first line
        int h = 0;           //Number of houses
        int addr[30000];     //Storing addresses
        int bestLoc = 0;     // Best location
        ssLine << aLine;     // writing aLine into ssLine;
        // Read the input data of each test cases
        while (ssLine >> addr[h])
            h++;
        sort(addr, addr + h);       // Sort all the addresses
        bestLoc = addr[(int)h / 2]; // Take median
        for (int j = 0; j < h; j++)
            dist[counter] += abs(addr[j] - bestLoc);
        //cout<<"Optimal : "<<best<<endl;
        //cout<<"Distance : "<<d[i]<<endl;
        ssLine.str(string()); // reset ssLine to an empty string
        ssLine.clear();       // reset flag “eof” to 0
        cout << dist[counter] << endl;
        counter++;
    }
}