#include "iostream"
using namespace std;
int mInverse(int n, int m)
{
    int ans = 1;
    while(ans < m)
    {
        if ((n % m) * (ans % m) % m == 1)
            return ans;
        else
            ans++;
    }
    return 0;
}
int main()
{
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        int a, b;
        cin >> a >> b;
        cout << mInverse(a, b) << endl;
    }
}