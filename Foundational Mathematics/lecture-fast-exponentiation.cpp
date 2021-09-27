#include <bits/stdc++.h>
using namespace std;

int binary_exponentiation(int a, int b, int mod = 1e9 + 7)
{
    int ans = 1;
    while (b)
    {
        if (b % 2)
            ans = (1LL * ans * a) % mod;
        a = a * a % mod;
        b /= 2;
    }
    return ans;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << binary_exponentiation(a, b, 10e9 + 1) << endl;
}