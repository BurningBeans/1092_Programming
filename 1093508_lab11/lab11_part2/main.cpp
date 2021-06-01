#include <iostream>
#include <string>
#include <algorithm> // std::sort
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int testcase; //Number of test cases
    string aLine;
    int dist[500] = {0}; // Storing distance
    int counter = 0;
    while (getline(cin, aLine))
    { // completing reading the first line
        int h = 0;           //Number of houses
        int addr[30000];     //Storing addresses
        int bestLoc = 0;     // Best location
        // Read the input data of each test cases
        for(int i = 0; i < aLine.size(); i++)
        {
            string temp("");
            int number = 0;
            while(isdigit(aLine[i]))
            {
                temp += aLine[i];
                i++;
            }
            if(temp != "")
            {
                int digits = 0;
                for (int j = temp.size()-1; j >= 0; j--)
                {
                    number += ((temp[digits] - '0') * pow(10, j));
                    digits++;
                }
                //cout << number << endl;
                addr[h] = number;
                h++;
            }
        }
        sort(addr, addr + h);       // Sort all the addresses
        bestLoc = addr[(int)h / 2]; // Take median
        for (int j = 0; j < h; j++)
            dist[counter] += abs(addr[j] - bestLoc);
        //cout<<"Optimal : "<<best<<endl;
        //cout<<"Distance : "<<d[i]<<endl;
        cout << dist[counter] << endl;
        counter++;
    }
}