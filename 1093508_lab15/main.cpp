#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <set>
#include <map>
using namespace std;
int main()
{
    ifstream infile1("b17.def", ios::in);
    ifstream infile2("x.lef", ios::in);
    map <string,string> MACROmap;
    string MARCO("MARCO");
    string input;
    while(infile2 >> input, input == MARCO)
    {

    }
}