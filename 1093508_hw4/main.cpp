#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int inverse(int a, int mod){
    int ans = 1;
    while (ans < mod){
        if ((a % mod) * (ans % mod) % mod == 1)
            return ans;
        else
            ans++;
    }
    return 0;
}

int main(){
    string infilename("hw4_spring_2021.in");
    string outfilename("o.out");
    ifstream infile(infilename);
    ofstream outfile(outfilename);
    int test_cases;
    infile >> test_cases;
    while (test_cases--){
        int a, b;
        infile >> a >> b;
        outfile << inverse(a, b) << '\n';
    }
    infile.close();
    outfile.close();
}
