#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
int binary_exponentiation(int a, int b, int mod = 1e9 + 7)
{
    int ans = 1;
    while (b)
    {
        if (b % 2)                       //gets the last bit
            ans = (1LL * ans * a) % mod; //multiply the a if last bit is 1 else not
        a = 1LL * a * a % mod;
        b /= 2; //deleting last bit
    }
    return ans;
}
lli binary_exponentiation2(lli a, lli b, lli mod = 1e9 + 7)
{
    lli ans = 1;
    while (b)
    {
        if (b % 2)                 //gets the last bit
            ans = (ans * a) % mod; //multiply the a if last bit is 1 else not
        a = a * a % mod;
        b = b >> 1; //deleting last bit
    }
    return ans;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << binary_exponentiation(a, b, 10e9 + 1) << endl;
    //to calculate a^-1 mod p = a^(p-2) mod P :: using Fermat's little theorem
    cout << binary_exponentiation2(a, 1e9 + 7 - 2, 1e9 + 7) << "\n";
}